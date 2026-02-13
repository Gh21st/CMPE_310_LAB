	.section	.bss
	.globl 	ram
	.lcomm 	ram, 	256 # Reserve 

	.section 	.text

	.globl 	fill_ram # Make function visisble to C program

fill_ram:
	mov 	$ram+0x50,	%rax
	mov		$ram+0x59,	%rcx 

again: 

	movb	$0x00,	(%rax)
	inc		%rax 
	cmp		%rax, %rcx
	jne		again

	ret	


.section .note.GNU-stack,"",@progbits
