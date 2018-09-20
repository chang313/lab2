/* 
 * CS:APP Data Lab 
 * 
 * Park Changhyeon 20170292


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
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */ 
int bitAnd(int x, int y) {
/* negate both x,y and compute 'or' bit operation. Then negate the result bit.*/
 return  ~((~x) | (~y));
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
 /* shift x to the right 8n bit. Then do 'and' operation with 0xff.*/
 int shift = (x >> (n << 3));
 return shift &  0xff;
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
 /* make cont such that first n bits are 0, others are 1. make arithmetic n shift 'arth' and then compute and operatioin them. */ 
 int cont = ~(((1 << 31) >> n) << 1);
 int arth = x >> n;

 return cont & arth;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
/* cont1 = 0101...0101 32 bit, cont2 = 00110011...0011 32 bit, cont3 = 00001111...00001111 32 bit, cont4 = 00000
 * 000111111110000000011111111 32 bit, cont5 = 00000000000000001111111111111111 32 bit.
 * first, x & cont1 collects x's odd digits bit, (x>>1) & cont1 collects x's even digits bit. adding them results * sum of odd and even digits. like this manner, repeating this process leads to sum of all digits which equals t * to the number of 1's. */ 
 int a = (0x55 + (0x55 << 8));
 int cont1 = a + (a << 16);
 int b = (0x33 + (0x33 << 8));
 int cont2 = b + (b << 16);
 int c = (0x0f + (0x0f << 8));
 int cont3 = c + (c << 16);
 int cont4 = 0xff + (0xff << 16);
 int cont5 = 0xff + (0xff << 8);

 int val = x;
 val = (val & cont1)+((val>>1) & cont1);
 val = (val & cont2)+((val>>2) & cont2);
 val = (val & cont3)+((val>>4) & cont3);
 val = (val & cont4)+((val>>8) & cont4);
 val = (val & cont5)+((val>>16) & cont5);
  return val;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
 /* except 0, x and -x have different most significant digits. so, do 'or' operation to x, -x and shift 
  * to the right 31 results 0xffffffff. For 0, it results 0. Add 1 to it, then except 0 all bits return 1. */
 int a = (x | (~x + 1)) >> 31 ;
 return a+1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { 
 /* minimum two's complement integer is 2^31 */
 return (1 << 31);
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
 /* cnt = 32 - n. shift to the left cnt and to the right again. if x can be represented as n-bit,
  * lower n bit of x and shifted are same so ^ operation results 0. 
  * if x is more than n-bit, there must be different bit between x and shifted at the postion upper than n.  */ 
 int cnt = 33 + (~n);
 int shifted = ((x << cnt) >> cnt);
 return !(x ^ shifted);
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
 /* if x is positive, just do x >> n. if x is negative, ((x-1) >> n) + 1. */

 int a = x >> 31;
 int c = ((a & 1) << n) + a;
 
 return ((x+c) >> n);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
 /* first, do 'not' operation and add 1. */
 int a = ~x +1;
  return a;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
 /* shift to the right 31 and then add 1. if positive, result is 1, if negative, result is 10(2).
  * if 0, result is 1. Do if only x is 0, !x is  1. do 'xor' operation to the 
  * shifted one and !x. */
 int a = (x >> 31) +1;
 return
 a^(!x); 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
 /* if x and y have different sign, done. Otherwise, let diff = y-x = y + (~x) +1.
  * Then apply same process like isPositive. then do '!' operation at last. */ 
 int diff  = y+ (~x) +1;
 int sign = x ^ y;
 return ((((sign & x) | (~sign & ~diff)) >> 31) & 1);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
 /* first, check whether the most significant 1 belongs to upper half of lower half. And then, check 
  * whether 1 belongs to upper part of it. Repeat this process until finding exact place of it. */
 int cnt = 0;
 cnt = (!!(x >> 16)) << 4;
 cnt += (!!(x >> (cnt + 8))) << 3;
 cnt += (!!(x >> (cnt +4))) << 2;
 cnt += (!!(x >> (cnt + 2))) <<1;
 cnt += (!!(x >> (cnt + 1)));
 return cnt; 
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
   /* if exp = 111...1 and frac != 0, then uf is NaN. except it, just change the sign bit. */
   int exp = 0xff << 23;
   int frac = (1 << 23) + (~0);
 
   if (((uf & exp) == exp) && (frac & uf)) 
      return uf;
 
   return uf ^ (1 <<31);
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
   /* if x is negative, change it to positive form. By the same manner as ilog2, find the 'e' value. 
    * Then find the Exp, and frac. When we find the frac, for the case that we should round it, then 
    * we consider each cases. */
   int unsign;
   int sign;
   int e = 0;
   
   if (x == 0) 
      return 0;
   if (x == 0x80000000) 
      return 0xcf000000;
   if (x >> 31) {
      unsign = ~x + 1;
      sign = 1;
   } else { 
      unsign = x;
      sign = 0;
   }
   if (unsign >> 16) 
      e += 16;
   if (unsign >> (8 + e))     
      e += 8;
   if (unsign >> (4 + e))
      e += 4;
   if (unsign >> (2 + e))
      e += 2;
   if (unsign >> (1 + e))
      e += 1;

   int exp = e + 127;
   int frac;
   int result = 0;
   int shift;
   if (e >= 23) {
      shift = e - 23;
      frac = (unsign >> shift) & 0x007fffff;
      if ((e >= 24) && ((unsign >> (e-24)) & 1))  {
         if (e == 24) {
            if (frac & 1) {
               if (frac == 0x00ffffff) {
                  frac = 0;
                  exp += 1;
               } else { frac +=1; }}}
         else if ((!(unsign << (56 - e))) && (frac & 1)) {
            
            if (frac == 0x00ffffff) {
               frac = 0;
               exp += 1;
            } else { frac += 1;}
         } else if (unsign << (56- e)) {
            if (frac == 0x00ffffff) {
               frac = 0;
               exp += 1;
            } else { frac += 1;}
         }
      }      
   } else {
      shift = 23 - e;
      frac = (unsign << shift) & 0x007fffff;
   }
   result = (sign << 31) + (exp << 23) + frac;
   return result;
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
   /* for +0, -0, return argument. For NaN and infinite, return argument. For small number whose exp part is 0, 
    * just shift to the left 1 bit. Otherwise, add 1 to the exp. */
   if (uf==0 || uf == 0x80000000)
       return uf;
  
   if(((uf>>23) & 0xff) == 0xff) 
      return uf;
  
   if(((uf>>23) & 0xff) == 0x00) {
      return (uf & (1<<31)) + (uf << 1);
   }
   return uf + (1<<23);

}
