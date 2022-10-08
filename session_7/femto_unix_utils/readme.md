# Femto Unix Utilities 

This project creates some basic utility functions immitating the basic Unix utilities. The provided commands and their usage are as follows. 

`mycp`: make a copy of a source file into a destination file, and keeps the source.

Usage: `mycp source_file dest_file`

`mymv`: make a copy of a source file into a destintation and removes the source.

Usage: `mymv source_file dest_file`

`myecho`: prints the message passed after the command.

Usage: `myecho message`

`mypwd`: prnts the current working directory

## Installation

To install Femto Unix Utilities, run the following commands from the project directory.

```
mkdir build
cd build
cmake ..
make
sudo make install
```

## Uninstallation 

There is a custom cmake rule provided in the CMakeList.txt file that uninstalls the installed files. To uninstall the awesome Femto Unix Utilities, run the command.

```
sudo make uninstall
```
