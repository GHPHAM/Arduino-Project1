; Lab2-2.asm
; Huy Pham
; 9/9/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data
val1    DWORD    1000h
val2    DWORD    2000h
val3    DWORD    3000h
val4    DWORD    4000h

.code
main    PROC
    MOV EAX, val1 ; 1000h
    NEG EAX       ;-1000h ; F F000
    ADD EAX, val2 ; 1000h

    MOV EBX, val3 ; 3000h
    ADD EBX, val4 ; 7000h

    SUB EAX, EBX  ;-6000h ; F A000


    INVOKE ExitProcess, 0
main    ENDP
END main