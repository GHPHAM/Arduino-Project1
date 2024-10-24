; pulse.asm
; Huy Pham
; 10/04/2024

.386
.model  flat,stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

INCLUDE Irvine32.inc

.data
dash       BYTE "-", 0
underline  BYTE "_", 0
    
myWord     DWORD 00000000h, 00000000h, 00000000h, 00000000h ; Initializing array to all 0
OUTPUT  BYTE "PLEASE ENTER FOUR DWORDS, ONE ON EACH LINE:", 0

.code
; FUNCTION TO CONVERT HEX TO BINARY AND PUT IT IN AX
binaryFromHex PROC USES ECX
    
    CMP AL, 00h
    JE case0

    CMP AL, 01h
    JE case1

    CMP AL, 02h
    JE case2

    CMP AL, 03h
    JE case3

    CMP AL, 04h
    JE case4

    CMP AL, 05h
    JE case5

    CMP AL, 06h
    JE case6

    CMP AL, 07h
    JE case7

    CMP AL, 08h
    JE case8

    CMP AL, 09h
    JE case9

    CMP AL, 0Ah
    JE caseA

    CMP AL, 0Bh
    JE caseB

    CMP AL, 0Ch
    JE caseC

    CMP AL, 0Dh
    JE caseD

    CMP AL, 0Eh
    JE caseE

    CMP AL, 0Fh
    JE caseF



    Case0:
    MOV AX, 0000h
    ret

    Case1:
    MOV AX, 0001h
    ret

    Case2:
    MOV AX, 0010h
    ret

    Case3:
    MOV AX, 0011h
    ret

    Case4:
    MOV AX, 0100h
    ret

    Case5:
    MOV AX, 0101h
    ret

    Case6:
    MOV AX, 0110h
    ret

    Case7:
    MOV AX, 0111h
    ret

    Case8:
    MOV AX, 1000h
    ret

    Case9:
    MOV AX, 1001h
    ret

    CaseA:
    MOV AX, 1010h
    ret

    CaseB:
    MOV AX, 1011h
    ret

    CaseC:
    MOV AX, 1100h
    ret

    CaseD:
    MOV AX, 1101h
    ret

    CaseE:
    MOV AX, 1110h
    ret

    CaseF:
    MOV AX, 1111h
    ret

binaryFromHex ENDP

; Feed binary (in hex form) to print out dashes or underline
printPulseSingle PROC USES ECX EBX EDX

MOV ECX, 4

binLoop:
    mov EBX, EAX
    push ECX

    dec ECX
    shl ECX, 2
    shr EBX, CL
    and EBX, 000Fh

    CMP BL, 00h
    JE bin0

    CMP BL, 01h
    JE bin1

    endBin:
    call WriteString

    pop ECX
    loop binLoop

    ret

bin0:
    MOV EDX, OFFSET underline ; Set EDX to message
    JMP endBin


bin1:
    MOV EDX, OFFSET dash ; Set EDX to message
    JMP endBin
    
printPulseSingle ENDP


; Print the full pulse of one single 32 bit (DWORD)
printPulse PROC USES EDX ECX
    mov ECX, 8              ; there's 8 hex in 32 bit DWORD

PulseLoop:
    mov EAX, [EDX]          ; Load the original value
    push ECX

    dec ECX                 ; Decrement by 1
    shl ECX, 2              ; Same as multiplying by 2^2 = 4
    shr EAX, CL             ; Shift right by the number of bits in CL
    and EAX, 000Fh          ; Mask out all but the least significant nibble

    call binaryFromHex      ; Convert the one single hex to bin and store in EAX
    call printPulseSingle   ; Print a single pulse

    pop ECX
    loop PulseLoop          ; Decrease ECX and repeat the loop until ECX = 0
    call Crlf               ; Move to the next line after printing all nibbles

    ret

printPulse ENDP


main    PROC
    CALL    Clrscr  ; Reset the console

    mov EDX, OFFSET myWord
    mov ECX, LENGTHOF myWord

    call ReadHex ; First hex
    mov [EDX], EAX

    call ReadHex ; Second hex
    mov [EDX + 4], EAX

    call ReadHex ; Third hex
    mov [EDX + 4 * 2], EAX

    call ReadHex ; Fourth hex
    mov [EDX + 4 * 3], EAX



    MOV ECX, 4   ; We print this out 4 times
printLoop:
    call printPulse
    ADD EDX, 4
    
    LOOP printLoop


    INVOKE ExitProcess, 0
main    ENDP
END main