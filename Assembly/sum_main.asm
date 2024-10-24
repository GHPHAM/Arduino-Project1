; Integer Summation Program(Sum_main.asm)
INCLUDE sum.inc
Count = 3
.data
prompt1 BYTE "Enter a signed integer: ", 0
prompt2 BYTE "The sum of the integers is: ", 0
array DWORD Count DUP(? )
sum DWORD ?
.code
main PROC
	call Clrscr
	INVOKE PromptForIntegers, ADDR prompt1, ADDR array,
Count
	INVOKE ArraySum, ADDR array, Count
	mov sum, eax
	INVOKE DisplaySum, ADDR prompt2, sum
	call Crlf
	exit
main ENDP
END main

MyProcedure PROC
	LOCAL buffer[20]:BYTE; Declare buffer as an array of 20 bytes
MyProcedure ENDP
