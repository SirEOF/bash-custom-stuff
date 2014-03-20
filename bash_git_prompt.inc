# Mostly took from http://bytebaker.com/2012/01/09/show-git-information-in-your-prompt/

function git-branch-name
{
    echo $(git symbolic-ref HEAD --short 2>/dev/null)
}

function git-dirty {
    st=$(git status --porcelain 2>/dev/null | wc -l)
    if [[ $st -gt 0 ]]
    then
		added=0
		modified=0
		deleted=0
        added=`   git status --porcelain |  grep '^[A|?]' | wc -l`		# DOES NOT WORK git diff --name-only --diff-filter=A
		modified=`git diff --name-only --diff-filter=MCRT | wc -l`
		deleted=` git status --porcelain |  grep '^D'     | wc -l`
		echo " ${Green}+${added} ~${modified} -${deleted}"
    fi
}

function git-unpushed {
    brinfo=$(git branch -v | grep `git-branch-name`)
    if [[ $brinfo =~ ("[ahead "([[:digit:]]*)]) ]]
    then
        echo "${Yellow}(${Red}${BASH_REMATCH[2]}${Yellow})"
    fi
}

function __git_prompt {
	status=$(git status &>/dev/null)
	if [[ $? -eq 0 ]]
	then
		echo " ${Yellow}[${IBlue}$(git-branch-name)$(git-unpushed)$(git-dirty)${Yellow}]${Color_Off}"
	else
		echo ""
	fi
}

function _prompt_command() {
	PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}${Green}${User}@${Host}${Color_Off}:${Blue}${PathShort}${Color_Off}`__git_prompt`\$ "
}


PROMPT_COMMAND=_prompt_command
