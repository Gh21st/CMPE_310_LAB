	.section	.bss
	.globl 	ram
	.lcomm 	ram, 	256 # Reserve 

	.section 	.text

	.globl 	fill_ram # Make function visisble to C program

fill_ram:
	mov 	$1,		%rcx # start 
	mov		$11,	%rdx # end 
	mov		$0, 	%rax # Accumulator 
again:
	add		%rcx,	%rax
	inc		%rcx
	cmp		%rcx,	%rdx
	jne 	again 
	
	mov		%rax, 	ram+0x50 
	ret	


.section .note.GNU-stack,"",@progbits
