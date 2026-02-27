# Isaac Boteler BA01014@umbc.edu 
# CMPE 310 LAB 2 HAMMING DISTANCE 
# find_hamming_distance function to calculate hamming distance between 2 strings 
	.section	.bss
	.globl 	string_1 
    .globl  string_2 

	.lcomm 	string_1, 		256 				# Reserve 
    .lcomm  string_2,       256  
    .section 	.text

	.globl 	find_hamming_distance				# Make function visible to C program

find_hamming_distance:
	mov		$0, %rbx 							# this is our index 
	mov		$0, %rax							# this is our aggregate 
hamming_loop:
	movb	string_1(%rbx), %cl					
	cmpb	$0, %cl								#check if str1 is null 						
	jz 		done
	movb	string_2(%rbx), %cl
	cmpb 	$0, %cl								#check if str2 is null 
	jz 		done 

	movb	string_2(%rbx),	%cl					# load first char 
	xor 	string_1(%rbx),	%cl 				# difference between chars 

	inc 	%rbx								# when byte_check is done, we load next addr 
byte_check:									 # cl register is read by bit, shifted left until null 
	test 	%cl,	%cl							# check for null 
	jz		hamming_loop			 

	mov		$1, 	%ch 						# check bit for cl 
	and		%cl,	%ch							# prepare for check
	shr 	%cl									# load next bit (shift byte right) 
	test 	$1,		%ch							# check for matching bit
	jz		byte_check							# bits are same, move on

	inc		%rax								# bits are not same, increase ham distance
	jmp		byte_check


	
done:
	ret

.section .note.GNU-stack,"",@progbits
