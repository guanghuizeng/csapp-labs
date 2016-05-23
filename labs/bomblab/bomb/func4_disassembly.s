
func4.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <func4>:
   0:	48 83 ec 08          	sub    $0x8,%rsp
   4:	89 d0                	mov    %edx,%eax
   6:	29 f0                	sub    %esi,%eax
   8:	89 c1                	mov    %eax,%ecx
   a:	c1 e9 1f             	shr    $0x1f,%ecx
   d:	01 c8                	add    %ecx,%eax
   f:	d1 f8                	sar    %eax
  11:	8d 0c 30             	lea    (%rax,%rsi,1),%ecx
  14:	39 f9                	cmp    %edi,%ecx
  16:	7e 0c                	jle    24 <func4+0x24>
  18:	8d 51 ff             	lea    -0x1(%rcx),%edx
  1b:	e8 00 00 00 00       	callq  20 <func4+0x20>
  20:	01 c0                	add    %eax,%eax
  22:	eb 15                	jmp    39 <func4+0x39>
  24:	b8 00 00 00 00       	mov    $0x0,%eax
  29:	39 f9                	cmp    %edi,%ecx
  2b:	7d 0c                	jge    39 <func4+0x39>
  2d:	8d 71 01             	lea    0x1(%rcx),%esi
  30:	e8 00 00 00 00       	callq  35 <func4+0x35>
  35:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
  39:	48 83 c4 08          	add    $0x8,%rsp
  3d:	c3                   	retq   
