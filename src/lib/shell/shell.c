void output(){};
char* input(){};


void shell(int argc, char* argv[]) // edit as appropriate for your kernel
{
    while (1) // you may want to provide a built-in "exit" command
    {
        char* command;
        int proc;
        output();               // display a prompt
        command = input_line();        // get a line of input, which will become the command to execute
        proc = process_start(command); // start a process from the command
        free(command);

        while (process_executing(proc))
        {
            if (input_line_waiting())
            {
                char* line;
                line = input();                 // read input from user
                process_send_input_line(proc, line); // send input to process
                free(line);
            }
            if (process_output_line_waiting(proc))
            {
                char* output;
                output = process_get_output_line(proc); // get output from process
                output_line(output);                    // write output to user
                free(output);
            }
        }
    }
}