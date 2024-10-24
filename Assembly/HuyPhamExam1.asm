; EXAM1.asm
; Huy Pham
; 9/25/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

INCLUDE Irvine32.inc

.data
buffer     BYTE 32 DUP(0)
myMsg      BYTE "Hello World", 0
myWord     DWORD 00000000h, 00000000h, 00000000h, 00000000h ; Initializing array to all 0

.code


main    PROC
    MOV EAX, lightGray + ( black * 16)   ; Set back to default
    CALL    SetTextColor
    CALL    Clrscr                       ; Reset the console

    mov EDX, OFFSET myWord
    mov ECX, SIZEOF myWord
    
    call ReadString ; First string

    add EDX, ECX

    call ReadString ; Second string

    add EDX, ECX

    call ReadString ; Third string

    add EDX, ECX

    call ReadString ; Fourth string

    mov EDX, OFFSET myWord ; Reset pointer
    mov EBX, ECX;   move the sizeof to EBX for increment

    ; Looping and printing
    MOV ECX, 4         ; Set the loop for 16
    L1: 
        PUSH ECX
        push EDX       ; Store for later
        MOV EAX, 0h
        MOV ECX, [EDX]
        MOV AL, CL
        shr EAX, 4
        shl EAX, 4 ; To only have one byte???


        MOV ECX, 4         ; Set the loop for 16

        ;MOV EAX, [EDX] ; Set background
        mov EDX, OFFSET myWord
        L2:
            push ECX
            push EDX
            MOV ECX, [EDX]
            MOV EDX, 0h
            MOV DL, CL
            shr EDX, 4
            
            push EAX    ; Push before adding so we have the origial AL back
            ADD AL, DL


            ;MOV AX, DX ; Set text
            ; WHY IS THIS NOT WORKING
            ; I don't know how to read them as one byte

            CALL    SetTextColor

            MOV EDX, OFFSET myMsg ; Set EDX to message
            call WriteString
            CALL    Crlf                        ; Go to next line
            
            pop  EAX
            pop  EDX            ; Pop it back to increment
            pop  ECX

            add EDX, EBX        ; Increment ; Is the incrementing not working?
        LOOP L2

        POP     EDX 
        POP     ECX
        ; EDX got changed to 0 somewhere here
        add EDX, EBX    ; Increment

    LOOP L1

    MOV EAX, lightGray + ( black * 16)   ; Set back to default
    CALL    SetTextColor
    CALL    Clrscr                       ; Reset the console

    INVOKE ExitProcess, 0
main    ENDP
END main
    