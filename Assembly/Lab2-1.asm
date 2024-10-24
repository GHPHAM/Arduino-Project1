; Lab2-1.asm
; Huy Pham
; 9/9/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data
myVar   BYTE 10h,20h,30h,40h,50h

.code
main    PROC
    MOV AL, myVar        
    ADD AL, myVar+1      
    ADD AL, myVar+2
    ADD AL, myVar+3
    ADD AL, myVar+4

    INVOKE ExitProcess, 0
main    ENDP
END main
