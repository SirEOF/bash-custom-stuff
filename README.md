bash-git-prompt
===============


Installation:

mkdir ~/bin
cd ~/bin
git clone git@github.com:facastagnini/bash-custom-stuff.git
echo << CADORNA >> ~/.bashrc
# adding some usefull constants
. ~/bin/bash-custom-stuff/bash_constants.inc
# adding git context to the shell
. ~/bin/bash-custom-stuff/bash_git_prompt.inc
CADORNA
bash

Done.
