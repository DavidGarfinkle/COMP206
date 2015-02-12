# .bashrc

# Source global definitions
if [ -f /usr/socs/Profile ]; then
        . /usr/socs/Profile
fi

# User specific aliases and functions
echo "Hello David! Type 'bkup' for backup of your source files";

#Immediately backup source files upon login
./Source/backup.sh

#Alias command 'bkup' to backup source files
alias bkup='./Source/backup.sh'

#Alias command 'lsa' to provide list of all files in current directory
alias lsa='ls -l -a';

#Change prompt to company motto
PS1='[\u][\h][\w]GIVE ME 100% plox';

