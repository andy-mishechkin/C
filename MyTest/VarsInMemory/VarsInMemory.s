	.file	"VarsInMemory.c"
	.text
	.globl	e
	.data
	.type	e, @object
	.size	e, 1
e:
	.byte	-85
	.globl	b
	.section	.data.rel.local,"aw"
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	e
	.globl	c
	.data
	.align 2
	.type	c, @object
	.size	c, 2
c:
	.value	4660
	.globl	t
	.align 4
	.type	t, @object
	.size	t, 4
t:
	.long	878082192
	.globl	a
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.quad	7023458830024590706
	.section	.rodata
.LC0:
	.string	"\n%p   "
.LC1:
	.string	"%02x  "
.LC2:
	.string	"%p   "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	movq	b(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -4(%rbp)
	jmp	.L2
.L4:
	movq	b(%rip), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, b(%rip)
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
	cmpl	$16, -8(%rbp)
	jne	.L3
	cmpl	$397, -4(%rbp)
	jg	.L3
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, -8(%rbp)
	movq	b(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	addl	$1, -4(%rbp)
.L2:
	cmpl	$399, -4(%rbp)
	jle	.L4
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
