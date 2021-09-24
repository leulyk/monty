# [monty](https://github.com/leulyk/monty)

<p float="left">
<img src="https://lh3.googleusercontent.com/oVJxT1yn7vwaEM8t9A5MGL6emG0j-_uqHa5H8ikWLvl6Ka-nVmUJZblqWDqPiY-S6itPLnZNgcc8rviK8AVT65l_a3zHiyctwy8=s0" width="245" height="150"/>
<img src="https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg" width = "150" height="150"/>
</p>

> This project contains an interpreter built for the Monty ByteCode. 
> **Project 0x19. C - Stacks, Queues - LIFO, FIFO**

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. 
Most of the industry uses this standard but it is not required by the specification of the language. 
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. 
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.
Comments begin with #.

## The monty program

- **Usage: monty file**, where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message **USAGE: monty file**, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message **Error: Can't open file (file)**, followed by a new line, and exit with the status EXIT_FAILURE
- If the file contains an invalid instruction, print the error message **L<line_number>: unknown instruction (opcode)**, followed by a new line, and exit with the status EXIT_FAILURE. Line numbers always start at 1.
- The monty program runs the bytecodes line by line and stop if either:
    it executed properly every line of the file
    it finds an error in the file
    an error occured
- If you can’t malloc anymore, print the error message **Error: malloc failed**, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Compilation & Output

> $ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

## Opcodes

| Opcode | Description |
| : -- : | : -- : |
| push | Usage: push <int>, pushes the element <int> to the stack |
| pall | prints all values on the stack |
| pint | prints the value at the top of the stack |
| pop | removes the top element of the stack |
| swap | swaps the top two elements on the stack |
| nop | does nothing |
| add | adds the top two elements, stores the result in the second top element, and removes the top element |
| sub | subtracts the top element of the stack from the second top element, stores the result in the second top element, and removes the top element |
| mul | multiplies the top two elements, stores the result in the second top element, and removes the top element |
| div | divides the second top element of the stack by the top element, stores the result in the second top element, and removes the top element |
| mod | computes the remainder of dividing the second top element of the stack by the top element, stores the result in the second top element, and removes the top element |
| pchar | prints the char at the top of the stack using the ASCII character set |
| pstr | prints the string starting from the top of the stack using the ASCII character set stopping if stack is over, if character is 0 or if value is not in ASCII table |
| rotl | rotates the stack to the top |
| rotr | rotates the stack to the bottom |
| stack | set the format of the data to stack (this is the default behavior of the program) |
| queue | set the format of the data to queue |
