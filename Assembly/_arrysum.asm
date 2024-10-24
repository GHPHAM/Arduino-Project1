; ArraySum Procedure (_arrysum.asm)
INCLUDE sum.inc
.code
;-----------------------------------------------------
ArraySum PROC,
 ptrArray:PTR DWORD, ; pointer to array
 arraySize:DWORD ; size of array
;
; Calculates the sum of an array of 32-bit integers.
; Returns: EAX = sum
;-----------------------------------------------------
    push ecx ; don't push EAX
    push esi
    mov eax,0 ; set the sum to zero
    mov esi,ptrArray
    mov ecx,arraySize
    cmp ecx,0 ; array size <= 0?
    jle L2 ; yes: quit

L1: add eax,[esi] ; add each integer to sum
    add esi,4 ; point to next integer
    loop L1 ; repeat for array size

L2: pop esi
    pop ecx ; return sum in EAX
    ret
ArraySum ENDP
END



AddThree PROC
	push    ebp     ; saves the base pointer
    mov     ebp, esp; put the the stack pointer in base pointer

    ; ebp + 8 is the 3rd pushed item, ebp + 12 is the 2nd, ebp + 16 is the 1st
    mov     eax, [ebp + 8]  ; deref ebp + 8 and move into eax
    add     eax, [ebp + 12] ; deref ebp + 12 and add into eax
    add     eax, [ebp + 16] ; deref ebp + 16 and add into eax

    pop     ebp     ; restore the base pointer
    ret
AddThree ENDP