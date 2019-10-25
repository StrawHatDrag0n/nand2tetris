// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
@i          //Setting i = 0
M=1
@R1
D=M
@n          //Setting n to no. of time to be added
M=D
@product
M=0
@R1
D=M
@STOP
D;JEQ
@R0
D=M
@STOP
D;JEQ
(LOOP)
@i
D=M
@n
D=D-M
@STOP
D,JGT

@R0   // r1+r0
D=M
@product
M=D+M

@i
M=M+1
@LOOP
0,JMP
(STOP)
@product
D=M
@R2
M=D
(END)
@END
0,JMP
