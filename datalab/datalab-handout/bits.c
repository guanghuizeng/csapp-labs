/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    // 要点: 关注信息的转换
    return ~((~x) | (~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // 要点: 理解乘法与left shift的关系. n << 3 => n * 8.
    return (x >> (n << 3)) & 0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    // 要点: 用arithmetic shift得到mask. 注意: y << n, 如果 n 小于 0, 是undefined操作.
    int m1 = (1 << 31) >> n;
    int m2 = m1 << 1;  // 去除多出的最左位(1)
    int m3 = ~m2;
    return (x >> n) & m3;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  return 2;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	// 本题要旨是区分0与其他数
	// 核心思想：若x为负数，则符号位可以作为区分标志；若x为正数，可以利用进位将有效信息集中到符号位上。

	// TODO (总结经验) 对于正数，利用进位, 加上0x7fffffff。

	int r1 = ((x>>31) & 0x1);   // r1 = 0 -> x 非负数；r1 = 1 -> x 负数；
	int r2 = (x+((1<<31)+((~1)+1)) >> 31) & 0x1;  // r2 = 0 -> x 非正数；r2 = 1 -> x 正数；

	// (r1 | r2) -> 0, 则x非负且非正, 即为0
	// (r1 | r2) -> 1, 则x为正数或负数
	return ((r1|r2)+1) & 0x1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    // 比2.70更多限制. 具体分析见文档.
    int y = x >> (n + ~0);
    return !y | !(~y);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	// 2.77
	// 关注信息流动。是否要加bias取决于x的正负性。而x的符号位蕴含了正负性！
    // 因此，合理的猜测是用x的符号位编码bias信息。说真的，尝试了才知道有很多可能性！
    int sign_bit = (x >> 31) & 0x1;
    int bias = (sign_bit << n) + (~sign_bit+1);
    return (x + bias) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // 注意正负数之间的bit patterns
	return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	// 注意边界：0. !(!x) => 0x00.
	return !((x >> 31) & 0x1) & !(!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	// x,y同号，组合符号信息与x和y的加法运算结果。
	// x,y异号，y >= 0 >= x. (1) 验证y的符号位是否为0; (2)验证x的符号位是否为1.
   
	int s1 = (x >> 31) & 0x1; // 改进：仅是比较s1与s2是否相同，不需要shift
	int s2 = (y >> 31) & 0x1;

	// 领悟到的方法：先尝试用额外的运算符表达语义, 掌握正确的解法，再用限定的运算符表示。

	int m0 = 1 << 31;
    int m = ~m0;
    int r1 = 0;
	int r2 = 0;

	// 核心：如果x与y符号相同，则比较去除符号位后的部分
	//	if ((s1 == s2) && (s1 == 0) && (((y & m) - (x & m)) >= 0)) { r1 = 1; }
	//  if ((s1 == s2) && (s1 == 1) && (((y & m) - (x & m)) >= 0)) { r1 = 1; }

	int sign = ((y & m) + (~(x & m) + 1)) & m0;
	r1 = !(s1 ^ s2) & (!sign);
	r2 = (s1 ^ s2) & s1;  

	return r1 | r2;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  return 2;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	// 本题的关键是理解float的编码规律。联系p.140。
	if ((uf & (~(1<<31))) > (0xFF << 23)) { return uf; } // NaN
	// 翻转符号位。方式1: 仍然从float的格式出发，利用unsigned加法的overflow性质, 使uf走向对立面。
	return uf + (1<<31);

	// 本题与csapp 2.92相同。现在看来，2.92的解法十分笨拙。
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

	// 本题要注意处理rounding. round-to-even.

	// 1. 符号位
    // 2. 取绝对值
    // 3. 计算从最左边的非0位到最右边的非0位之间的长度
	
	// denormalized value
	if (x == 0) { return 0; }

	int sign = 0;
	if (x < 0) { sign = 1; x = -x; }
	
	int y = x;
	int count = 0;
	while (y > 0) {
		y = y << 1;
		count++;
	}

	int length = 31 - count;
	// TODO rounding问题
	if (length > 23) {
		int s = length - 23;	   
		int right = ((1<<s)-1) & x;
		int least = (1<<s) & x;
		int shift_least = least >> 1;
		int half = 1<<(s-1);

		if (right > half) {
			x = x + (1<<s); // 进位 
		} else if (right == half) {
			x = x + shift_least;  // round-to-even
		} else {
			; // 舍去
		}

		count = 0;
		while (x > 0) {
			x = x << 1;
			count++;
		}
	} else {
		x = y;
	}
	
	int bias = 127;
	int exp = ((31-count) + bias) & 0xff;
    int frac = ((x & (0x7fffff<<8))) >> 8;

	return (sign << 31) | (exp << 23) | frac;

	// TODO 虽然已经通过测试，但是还要做优化。
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	/* float: |31|30-23|22-0| */
	// 参考figure 2.34(p.140)

	unsigned m = 0;
	unsigned sign = 0;
	unsigned exp = 0;
	unsigned frac = 0;

	m = 1 << 31;
	sign = 0;
	if (uf >= m) {
		sign = m;
		uf = uf - m;
	}

	exp = (uf >> 23) & 0xff;
	frac = uf & 0x7fffff;
	
	if (exp == 0) {
		return sign +  (frac << 1);
	} else if (exp == 0xff) {
		return sign + uf;
	} else {
		return sign + ((exp + 1) << 23) + frac;
	}

	// 关键是处理 denormalized values 和 special values.
}
