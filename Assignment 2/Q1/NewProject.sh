#!/bin/bash

#Check if there is at least one argument passed from command line
if [ -z $1 ]; then
	echo "Project name is missing. Type in: NewProject project_name"
	exit 0

#Check if there is at most one argument passed from the command line
elif [ "$#" -ne 1 ]; then echo "Your Project name must be a single word. Type in: NewProject project_name"
	exit 0

#Store the project name to a recognizable variable
else project_name="$1"
fi

#Create parent directory and four subdirectories: docs, source, backup, archive
mkdir -p $project_name $project_name/docs $project_name/source $project_name/backup $project_name/archive

#Create compile script inside source folder
echo "

#!/bin/bash	

#Check for valid arguments (either 1 or 2):
# 1) -o switch and executable filenames
# 2) filenames

#If 1) or 2) have not been satisfied, then return error 
if ! [[ \"\$1\" = \"-o\" && -n \$3 || \"\$1\" != \"-o\"  &&  -n \$1 ]];
then
	echo \"You are missing file names. Type in: compile -o executable file(s) or compile file(s)\"
	exit 0
fi

#Tar backup files and move them to archive directory with name-date format
tar -cf backup.tar ../backup
mv backup.tar ../archive/backup_\$(date +\"%m_%d_%Y\").tar 

#Copy all source files into backup directory without prompting about overwriting files
cp -af ./* ../backup

#COMPILE the program using gcc
gcc \$@ 2> ./errors.txt #redirect error stream to errors txt file and overwrite if necessary

#Display errors.txt file
more errors.txt

" >> $project_name/source/compile
chmod 777 ./$project_name/source/compile



