# Simple Shell Extension

This project creates a simple shell immitating bash. This simple shell supports the following.

1. Pushing Enter moves cursor to next line.

2. Running Linux command line inputs through the use of (execvpe system call). 

3. Accepting multiple arguments (example ls -l /home) should work, and the arguments are passed to the newly launched process. 

4. Adding local variables (example sysprog=awesome). The shell supports two relatedcommands

    - The `set` command lists the current variables

    - The `export` command adds a local variable, if available, to the environment variables (using the setenv function).
    

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
