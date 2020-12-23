# Monty

Monty Interpreter
This reposittory is for a program that interprets Monty ByteCode files in C language.

Motivation
We are building our interpreter to deepen our understanding of stacks and queues and when to use them. We've learned the meaning of LIFO and FIFO through this practice. 

Build status :: Features
Our interpreter, when run with a Monty file, will open that file and then go through the opcodes line by line. Our program will call the corresponding function by parsing each line to seperate the opcode from the data pertaining to that opcode, if any. Opcodes that are functional: push, pall, pint, pop, swap, add, nop, sub, div, mul, mod, pchar, pstr, rotl, and rotr.