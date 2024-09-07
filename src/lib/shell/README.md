



What is a shell?
A shell is a userspace application that provides a simple interface to an operating system kernel. The simplest shell performs the following tasks:

Execute other userspace binaries
Provide input data for the binaries executed
Provide a means for the executing binaries to output data
A shell may also offer other features depending on the operating system targeted, such as a means to set and use environment variables if such a concept exists in the kernel. The way that a shell is designed depends heavily on the operating system targeted, for example if the operating system has the concept of a "working directory" then the shell may want to maintain its own working directory which will become the working directory of any binaries executed (and provide commands to change the working directory, which may be a built-in command - a command handled by the shell itself, rather than an external binary - such as the cd command in the BASH shell).

Depending on the design of the kernel, the shell may provide input and output facilities through the "standard input" and "standard output" streams provided by the kernel to each executing binary. In this case, the shell will typically offer some form of output redirection, whereby input may be read from a file and output may be written to a file or passed as input to a second binary; unredirected input will typically be read from the shell's own "standard input" stream and unredirected output will typically be written to the shell's own "standard output" stream.

As a shell is a form of user interface, it will typically read input from the user (which may, as aforementioned, occur through its "standard input" stream) and display output to the user. It's important, however, to get the distinction between the physical hardware used to interact with the user and the shell's interface with the user. For example, the user may be working at a physical keyboard and monitor attached to the computer, or they may be connected over a network, or they may be using a serial console. A versatile shell should be able to work in all of these situations, reading input and sending output through whatever device the user is using (of course, this may not be possible in all operating systems, unless a concept analogous to the UNIX "standard input" and "standard output" is present in the kernel, or the kernel provides some other way of abstracting input devices or emulating one input device as another).

Typically, thus, a simple shell will do the following for each binary executed:

Read a command from the user, which becomes the name of the binary to execute plus any command-line arguments (if applicable)
Tell the kernel to execute the binary
Read input from the user and send it to the binary
Read output from the binary and send it to the user
Repeat steps 3 and 4 until the binary terminates
In order to do this, the shell will require the following:

A kernel with an API call for executing a binary
A way to get input from the user (typically, this requires a keyboard driver for the kernel and an API call for reading from the keyboard - may take the form of "standard input")
A way to send output to the user (typically, this requires a video driver for the kernel and an API call for printing text to the screen - may take the form of "standard output")
It's probably also desirable for the user to be able to edit their commands without having to type them all over again, so a set of string editing functions (ala GNU readline) are also preferable.