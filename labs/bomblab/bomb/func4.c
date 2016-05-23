

/**
 * 用 GCC 在 ubuntu 14.10 生成的汇编代码，与bomb的汇编代码一致
 *
 * 1. $: gcc -O1 -c func4.c   # func4.o
 * 2. $: objdump -d func4.c   # func4.s
 *
 * phase_4的要求是：x未知，y=0, z=0xe. 需要返回的正确结果是0.
 * 在有了func4的函数实现后，我们的任务是确定x的值。
 */

int func4(int x, int y, int z) {
	// x : rdi, y : rsi, z : rdx
	
	int s1 = z - y;
	s1 = ((unsigned)s1 >> 0x1f) + s1;    // 加上符号
	s1 = s1 >> 1;                        // 除以2
	int s2 = s1 + y;

	// if (s1 >= 0) { int s2 = (z-y) / 2 + y; }
	// if (s1 < 0) { int s2 = (((z-y)+1) / 2) + y;
	
	int r = 0;
	if (x < s2) {
		z = s2 - 1;
		r = func4(x, y, z);
		r = 2 * r;
	} else if (x > s2) {
		y = s2 + 1;
		r = func4(x, y, z);
		r = 2 * r + 1;
	}
	return r;
}

// test
int main() {
	int x = 0;
	int y = 0;
	int z = 0xe;

	printf("output: %d\n", func4(x,y,z));

	return 0;
}
