	.data
num1:	.asciiz "Digite o primeiro numero: "	

num2:	.asciiz "Digite o segundo numero: "

res:	.asciiz "O resultado é: "

	.text
	.globl main

main:

	addi $t0, $zero, 100 

	#Imprimir num1 request
	li $v0, 4
	la $a0, num1
	syscall
	
	#read num1 
	li $v0, 5
	syscall
	move $t0, $v0
	
	#Imprimir num2 request
	li $v0, 4
	la $a0, num2
	syscall
	
	#read num2
	li $v0, 5
	syscall
	move $t1, $v0
	
	
	beq $t0, $zero, else

	sub  $s0, $t0, $t1
	add  $s0, $s0, 1
		
	j endif
	
else:
	add  $s0, $t1, $t0
	sub  $s0, $s0, 1
endif:

	#Imprimir result
	li $v0, 4
	la $a0, res
	syscall
	
	#Imprimir o int
	li $v0, 1
	move $a0, $s0
	syscall
