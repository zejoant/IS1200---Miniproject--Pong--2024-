  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.global delay 
.global time2string
.global enable_interrupt

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
.data 
.align 2
.text 


hexasc:
	andi $v0, $a0, 0xF
	li $t0, 9
	ble $v0, $t0, nums
	nop
	addi	$v0, $v0, 55		#if number is 10 or more
	jr $ra
	nop
	nums:				#if number is less than 10
		addi	$v0, $v0, 0x30
		jr $ra
		nop

delay:
	PUSH $s0
	
	li $s0, 0xF #FFFFF #4711
	
	delay_while:					#loops the amount of times stored in $a0
		ble $a0, $zero, delay_end
		nop
		addi $a0, $a0, -1
		
		delay_for:				#loops the amount of times stored in $s0
			beq $s0, $zero, delay_for_end
			nop
			addi $s0, $s0, -1
			j delay_for
			nop
		delay_for_end:
		
		j delay_while
		nop
	delay_end:
	
	POP $s0
	
	jr $ra
	nop

time2string:
	PUSH $ra
	PUSH $s0
	PUSH $s1
	PUSH $s2

	move $s0, $a0		#moves address to s0
	move $s1, $a1		
	
	andi $a0, $s1, 0xF000 	#masks value
	srl $a0, $a0, 12
	jal hexasc 		#converts the fourth timestr number to ascii
	nop
	sb $v0, 0($s0)		#stores it in the adress of $a0
			
	andi $a0, $s1, 0xF00 	#masks value
	srl $a0, $a0, 8
	jal hexasc 		#converts the third timestr number to ascii
	nop
	sb $v0, 1($s0)		#stores it in the adress of $a0
	
	li $t6, 0x3A		#add :
        sb $t6, 2($s0)
			
	andi $a0, $s1, 0xF0 	#masks value
	srl $a0, $a0, 4
	jal hexasc 		#converts the second timestr number to ascii
	nop
	sb $v0, 3($s0)		#stores it in the adress of $a0
			
	andi $a0, $s1, 0xF 	#masks value
	jal hexasc 		#converts the first timestr number to ascii
	nop
	sb $v0, 4($s0)		#stores it in the adress of $a0
	
	li $t6, 0x00		#removes print of "more text" for some reason
        sb $t6, 5($s0)
        
        andi $a0, $s1, 0xFFFF
        bne $a0, $0, ifZero
        nop
        li $s2, 0x52554f48
        sw $s2, 0($s0)
        sb $0, 4($s0)
        ifZero:
        
        move $a0, $s0		#returns address to a0
	
	POP $s2
	POP $s1
	POP $s0
	POP $ra
	jr $ra
	nop

	enable_interrupt:
    ei
    jr  $ra
    nop
