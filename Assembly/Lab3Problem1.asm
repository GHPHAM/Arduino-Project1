; Lab3Problem1.asm
; Huy Pham
; 9/18/2024

; Randomize a bunch of strings with random length 20 times.

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

INCLUDE Irvine32.inc

.data

.code

; RANDOMIZE A CAPITAL LETTER INTO EAX
randomChar PROC
    MOV EAX, 25   ; Set the random 0 - 25
    CALL RandomRange ; rand number is now in EAX
    ADD EAX, 65 ; move the number to ASCII range
    ret
randomChar ENDP

; PRINT A RANDOM STRING OF RANDOM LENGTH TO THE CONSOLE
RandomString PROC USES ECX
    MOV EAX, 5                  ; Set the random 0 - 5
    CALL RandomRange            ; Get the random number
    ADD EAX, 5                  ; Move the range to 5 - 10
    MOV ECX, EAX                ; Set the loop

    L2:
        CALL randomChar         ; Get a random character in EAX
        CALL WriteChar          ; Print out char in AL
    LOOP L2

    CALL Crlf                        ; Go to next line
    ret
RandomString ENDP




main    PROC
    MOV ECX, 20                 ; Set loop to run 20 times
    CALL Randomize              ; set the seed

    L1:
        CALL RandomString
    LOOP L1

    INVOKE ExitProcess, 0
main    ENDP
END main
    