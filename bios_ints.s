;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; bios_ints.h: helper functions to access bios interrupts  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Sets the text-mode attributes for the whole 80x25 screen
; call  with AL = attribute (hi nibble = background, lo-nibble = foreground)

global set_text_attributes

set_text_attributes:
    push    es              ; save the seg register
    mov     cx, 80*25       ; # of chars to do
    mov     bx, 0xB800      ; segment of the screen memory for this video mode
    mov     es, bx
    xor     di, di          ; point to char data of screen-pos 0,0
.set_text_attributes_loop:
    inc     di              ; advance by 1 to point to the attribute, rather than the char
    stosb                   ; store our attribute byte to [es:di] and increment di. di now points to a character
    loop    .set_text_attributes_loop
    pop     es
    ret

; Read a character using BIOS interrupt
global read_char

read_char:
    mov ah, 0x0
    int 16h
    sti
