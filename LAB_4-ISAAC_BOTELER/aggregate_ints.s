#Isaac Boteler BA01014@umbc.edu 
#CMPE 310 LAB 4 
#Function, reads ints from array outputs sum 
    .section    .text 
    .globl  find_sum
#Function, arguments: %rdi, %rsi return in %rax
#rdi : first index of array 
#rsi : number of values 
find_sum: 
#Load 0 into %rax (I am fancy)
xor     %rax,   %rax
#Using %rbx and %rcx for bounds  
xor     %rbx,   %rbx            #rbx incrementer 
mov     %rsi,   %rcx            #rcx is length


another: 
cmp     %rbx,   %rcx
jz      done 
add     (%rdi,%rbx,8), %rax     #we are using quads so we jump by 8

inc     %rbx 
jmp     another 

#Returns %rax 
done: 
    ret 

.section .note.GNU-stack,"",@progbits
