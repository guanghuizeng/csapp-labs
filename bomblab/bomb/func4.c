
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
