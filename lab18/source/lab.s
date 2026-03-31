bits 64

section .text

global to_grayscale_red

to_grayscale_red:
    ; to_grayscale_red(char *buffer, int width, int height, int channels)
    ;           edi          esi        edx         ecx
    push    rbx; пушим на стэк чтобы сохранить значения
    push    r14
    ;push    r15
    mov     r8, rdx     ; r8d - height
    mov     r9, rcx     ; r9d - channels

    xor     r10, r10    ; r10d - index

    mov     rcx, r8
    cmp r9, 4 ;sravnivaem znachenie canala s 4
    je rgba
rgb:
    .height_loop:
        push    rcx

        mov     rcx, rsi; width
        .width_loop:
            push    rcx

            mov     r14b, byte [rdi + r10]    ; r14b - red channel

            mov     byte [rdi + r10 + 1], r14b ; green = red
            mov     byte [rdi + r10 + 2], r14b ; blue = red

            add     r10, r9  ; next pixel

            pop     rcx
            loop    .width_loop

        pop     rcx
        loop    .height_loop

    ;pop     r15
    pop     r14
    pop     rbx
    ret
rgba:
	.height_loopa:
        push    rcx

        mov     rcx, rsi
        .width_loopa:
            push    rcx

            mov     r14b, byte [rdi + r10]    ; r14b - red channel

            mov     byte [rdi + r10 + 1], r14b ; green = red
            mov     byte [rdi + r10 + 2], r14b ; blue = red
	    mov     byte [rdi + r10 + 3], r14b ; alpha = red
            add     r10, r9  ; next pixel

            pop     rcx
            loop    .width_loopa

        pop     rcx
        loop    .height_loopa

    ;pop     r15
    pop     r14
    pop     rbx
    ret
