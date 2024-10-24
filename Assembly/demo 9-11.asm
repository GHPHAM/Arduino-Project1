.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
;varB    BYTE 65h,31h,02h,05h
;varW    WORD 6543h,1202h
;varD    DWORD 12345678h



.code
main PROC
    ;MOV AX,WORD PTR [varB + 2]
    ;MOV BL,BYTE PTR varD
    ;MOV BL,BYTE PTR [varW + 2]
    ;MOV AX,WORD PTR [varD + 2]
    ;MOV EAX,DWORD PTR varW;

    mov bx, 0FFFFh
    and bx, 6Bh
    Invoke ExitProcess, 0

main ENDP
END main