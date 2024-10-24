; Lab2-3.asm
; Huy Pham
; 9/11/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data
myArray   BYTE 11h,22h,33h,44h

.code
main    PROC
    MOV EAX, SIZEOF myArray  
    MOV EBX, 2
    XOR EDX, EDX
    DIV EBX                  ; Divide EAX by 2 
    MOV ECX, EAX             ; Move the result into ECX

    MOV EAX, OFFSET myArray ; Find the adress of the first element of myArray
    MOV EBX, OFFSET myArray ; ditto
    ADD EBX, LENGTHOF myArray - 1; add the length - 1 to get to the last element of the array

L1:
    MOV DL, [EAX]                 ; Move the content of address at EAX into DL
    MOV DH, [EBX]                 ; Move the content of address at EBX into DH
    ;XCHG AL, BL                   ; Swap AL and BL; xchg can't work on memory directly.
    MOV [EAX], DH                 ; Store the swapped byte at the start
    MOV [EBX], DL                 ; Store the swapped byte at the end

    INC EAX
    DEC EBX

    LOOP L1

    INVOKE ExitProcess, 0
main    ENDP
END main
