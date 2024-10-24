; Lab3Problem2.asm
; Huy Pham
; 9/18/2024
; Print out 256x256 A, each with different combination of font color and background color

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

INCLUDE Irvine32.inc

.data

.code


main    PROC
    MOV EAX, lightGray + ( black * 16)   ; Set back to default
    CALL    SetTextColor
    CALL    Clrscr                       ; Reset the console


    MOV ECX, 16         ; Set the loop for 16
    L1:
        PUSH    ECX;
        MOV EBX, ECX    ; Store ECX for EBX
        DEC EBX         ; Decrement EBX once
        
        MOV ECX, 16     ; Set internal loop for 16
        
        
        L2:
            MOV EDX, ECX
            DEC EDX                         
            SHL EDX,4                       ; Shift the background color
            ADD EBX, EDX                    ; Set background color and foreground color.

            MOV     EAX, EBX
            CALL    SetTextColor

            MOV     AL, 65                  ; Assign A to AL
            CALL WriteChar                  ; Write a letter in AL
        LOOP L2

        POP     ECX;
    LOOP L1

    MOV EAX, lightGray + ( black * 16)   ; Set back to default
    CALL    SetTextColor

    CALL    Crlf                        ; Go to next line
    CALL    WaitMsg                     ; Give users a chance to read
    CALL    Clrscr                      ; Call clrscr to reset background color

    INVOKE ExitProcess, 0
main    ENDP
END main
    