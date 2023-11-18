#include "monty.h"
/* Define instruction set (replace this with your actual instruction set) */
instruction_t instruction_set[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    /* Add other opcodes as needed */
};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line = NULL, *opcode, *arg;
    size_t len = 0, read, i;
    unsigned int line_number = 0;
    int value, found = 0;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
	file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
	while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        /* Remove newline character at the end of the line */
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        /* Tokenize the line */
        opcode = strtok(line, " ");
        if (opcode != NULL)
        {
            /* Check if the line is not a comment */
            if (opcode[0] != '#')
            {
                /* Find corresponding function for the opcode and execute it */
                if (strcmp(opcode, "push") == 0)
                {
                   arg = strtok(NULL, " ");
                    if (arg == NULL || !isdigit(arg[0]))
                    {
                        fprintf(stderr, "L%u: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                    }
                    value = atoi(arg);
                    push(&stack, value);
                }
                else
                {
                    for (i = 0; i < sizeof(instruction_set) / sizeof(instruction_set[0]); i++)
                    {
                        if (strcmp(opcode, instruction_set[i].opcode) == 0)
                        {
                            instruction_set[i].f(&stack, line_number);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                    {
                        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return (EXIT_SUCCESS);
}
