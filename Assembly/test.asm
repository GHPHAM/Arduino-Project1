; Lab2 - 3.asm
; Huy Pham
; 9 / 11 / 2024

.386
.model  flat, stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data

original dword 00000000h ;stores the original

.code

; Multiplier in EBX
; Multiplicant in EAX
; Multiplicant buffer in ECX
; sum to add back in EDX
BitwiseMultiply PROC
    cmp EBX, 0h            ; Return if multiplying by zero
    JE divByZero;

    mov [original], EAX    ; Store the original value
    mov EAX, 0h
    mov ECX, 2             ; Priming the multiplier

loop1:
    cmp EBX, 0h            ; Return if multiplier is zero
    JE return              ; Changed from JMP to JE

    cmp EBX, 1h
    je addOnce             ; Corrected from JMP to JE

    shl ECX, 1             ; Shift left to double EDX (if necessary)
    cmp ECX, EBX           ; Check if EDX is greater than EBX
    jg shiftBackOnce       ; If so, shift back

    jmp loop1; Continue the loop

multiplying:
    mov edx, [original]    ; Load the original value into ECX

    sub EBX, ECX           ; Decrement EBX by EDX

    shr ecx, 1             ; divide ecx by 2
    shl edx, cl            ; Shift ECX left the ecx
    add EAX, edx           ; Add the result to EAX
    mov ECX, 2             ; Priming the multiplier

    jmp loop1              ; Continue the loop

shiftBackOnce:
    shr ECX, 1             ; Shift right to adjust EDX back
    jmp multiplying

divByZero:
    mov EAX, 0h            ; Set EAX to 0
    jmp return 

addOnce:
    add EAX, [original];    ; Add the original value directly
    jmp return

return:
    ret
BitwiseMultiply ENDP


main    PROC
    mov EAX, 2h
    mov EBX, 7h
    call BitWiseMultiply


    INVOKE ExitProcess, 0
main    ENDP
END main
