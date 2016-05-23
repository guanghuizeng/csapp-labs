	.file	"func4.c"
	.text
	.p2align 4,,15
	.globl	func4
	.type	func4, @function
func4:
.LFB0:
	.cfi_startproc
	movl	$1, %r8d
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L2:
	movl	%edx, %ecx
	subl	%esi, %ecx
	movl	%ecx, %r9d
	shrl	$31, %r9d
	addl	%r9d, %ecx
	sarl	%ecx
	addl	%esi, %ecx
	cmpl	%edi, %ecx
	jge	.L3
	leal	-1(%rcx), %edx
	addl	%r8d, %r8d
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	jle	.L5
	addl	%r8d, %eax
	leal	1(%rcx), %esi
	addl	%r8d, %r8d
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L5:
	rep ret
	.cfi_endproc
.LFE0:
	.size	func4, .-func4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
