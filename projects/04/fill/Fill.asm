// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

	@SCREEN
	D=A
	@addr
	M=D	
	
		(START)			
		@i
		M=0
	
	(KBDSCAN)
		@KBD
		D=M
		@BLACK
		D;JGT	//D>0 jump (BLACK)
		@WHITE
		D;JEQ	//D=0 jump (WHITE)
		@KBDSCAN
		0;JMP
	
	(BLACK)		
		
		@24575
		D=M
		@KBDSCAN
		D;JLT
		
	//@k
		//D=M
		
		@addr
		A=M 
		M=-1
		@i 
		M=M+1	
		@addr
		M=M+1
			
		
        @END
        0;JMP 
		
	(WHITE)
		@i 
		D=M 
        @START
		D;JEQ
		
		@addr
		A=M 
		M=0	
		@i 
		M=M-1	
		@addr
		M=M-1
		@END
        0;JMP 
				
	(END)
	
		@KBDSCAN
		0;JMP