	.data
nums:	.word 2,4,6,8,10,12,14,16,18,20

	.text
	.globl main

main:	
	add $t0, $t0, $zero	#total = t0 = 0
	addi $t1, $zero, 0	#i = t1 = 0
	addi $t2, $zero, 9	#n = t2 = 9
	la $t4, nums		#V = t4 = posição inicial do vetor na memória

loop:
    bgt $t1,$t2,exit
        lw      $t3,0($t4)              # load array[i]
     	addi    $t4,$t4,4               # increment array pointe
        add     $t1,$t1,1             # update sum4,4 
        add     $t0,$t0,$t3            # get val * val
    	add     $t5,$t5,$t6  
    j loop  

exit:

	#Faça seu código a partir deste ponto.

