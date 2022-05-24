all:
	nasm -f elf32 -g -F dwarf boot.asm -o boot.o
	nasm -f elf32 -g -F dwarf lowlevel.asm -o lowlevel.o
	i686-elf-gcc -g -m32  -c keyb.c -o keyb.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c common.c -o common.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c idt_int.c -o idt_int.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c monitor.c -o monitor.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c theme.c -o theme.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c initos.c -o intios.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c apleniteos.c -o apleniteos.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -c main.c -o main.o -ffreestanding -O3 -Wall -Wextra -pedantic
	i686-elf-gcc -g -m32  -Wl,--build-id=none -T link.ld -o multiboot.elf -ffreestanding -nostdlib lowlevel.o intios.o apleniteos.o main.o idt_int.o theme.o common.o monitor.o keyb.o boot.o -lgcc

clean:
	rm *.o multiboot.elf