; AddTwo.asm - add two 32 - bit integers
; Chapter 3 example
; Huy Pham
; 9/4/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data
myVar   DWORD 11223344h, 55667788h, 99AABBCCh

.code
main    PROC
    MOV EAX, myVar        ; AL = 10h
    ADD EAX, myVar+4      ; AL = 30h
    ADD EAX, myVar+8      ; AL = 60h

    INVOKE ExitProcess, 0
main    ENDP
END main

