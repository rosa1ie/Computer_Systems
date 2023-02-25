// Authors: Rosalie Lee, Ichhit Joshi

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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */


/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);  // A and B = ~(not A or not B)
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;   // 0x80000000 is the minimum
}

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
  int one = x & y;    // Assigning 1 when both are 1
  int zero = ~x & ~y;   // Assigning 1 when both are 0
  return ~(~one & ~zero);   // Returning 1 when either or both of cases are 1
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int x_and_y = x&y;
  int x_or_y = ~(~x&~y);    // A or B = ~(not A and not B)
  return x_or_y & ~x_and_y;   // A Xor B = (A or B) and ~(A and B) by using k-map
}


/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x >> (n<<3)) & 0xff; //shifting so that the byte that we want is at the rightmost end and using a 0xff mask to get just that byte
}

/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int mask = 0x55 << 24 | 0x55 << 16 | 0x55 << 8 | 0x55;   // Creating 0x55555555 to and with input.
  return !((x&mask)^mask); // check if the even numbered bits are equal to the mask
}


/*
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    int notx = !x; // get negation of x using logical not
    return notx | y; // returns 1 if either not x or y is 1, indicating true
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
  int shift = 32 + ~n + 1; // calculate 32 - n value to shift
  int shifted = (x<<shift) >> shift;
  return !(x ^ shifted); // if x and shifted are equal then it is possible to represent as 2's complement
}


/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
  int def_neg = x >> 31;  // checking the first digit of the binary to see if it is negative
  int round_up = (1 << n) + ~0; // calculating the value to add for rounding up if needed
  int round = def_neg & round_up; // anding the previous calculation when x is negative
  return (x + round) >> n;  // adding previous result to x to get the binary and it will return the divided value after shifting n times
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1; // flipping the bits gives ones complement and adding 1 to the result gives the 2's complement form
}


/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x){
  int get_sign = ((x & (1 << 31)) >> 31 ); //get the sign bit
  get_sign = get_sign | !x; // check if sign bit is positive or negative or !x for the case when input x is 0
  return !get_sign;
}



/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x) {
  int mask, start, upper16, left, right;
  mask = (0xFF << 8) | 0xFF;   // create a mask to set the lower 16 bits
  start = x & mask;            // get the lower 16 bits of x
  upper16 = (x >> 16) & mask;  // get the upper 16 bits of x

  mask = 0xFF;                     // reset mask to 0xFF
  left = (start & mask) << 8;  // get the leftmost byte of the lower 16 bits and shift it to the left
  right = (start >> 8) & mask; // get the rightmost byte of the lower 16 bits and shift it to the right
  start = left | right;            // combine the left and right bytes of the lower 16 bits

  mask = (0xF << 8) | 0xF;         // create a mask to swap 4 bits
  left = (start & mask) << 4;      // get the left 4 bits and shift it to the left
  right = (start >> 4) & mask;     // get the right 4 bits and shift it to the right
  start = left | right;            // combine the left and right 4 bits

  mask = (0x33 << 8) | 0x33;       // create a mask to swap adjacent pairs of bits
  left = (start & mask) << 2;      // get the left pair of bits and shift it to the left
  right = (start >> 2) & mask;     // get the right pair of bits and shift it to the right
  start = left | right;            // combine the left and right pairs of bits

  mask = (0x55 << 8) | 0x55;       // create a mask to swap alternate bits
  left = (start & mask) << 1;      // get the left bit and shift it to the left
  right = (start >> 1) & mask;     // get the right bit and shift it to the right
  start = left | right;            // combine the left and right bits

  return !(start ^ upper16);       // returns true if start and upper16 are equal, false otherwise
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
  int mask = ~(1 << 31 >> n << 1); // set all bits to one except for the leftmost n bits
  return (x>>n) & mask; // mask sets leftmost n bits to zero and the rest is unchanged
}


/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  int diff1 = x + ~0x2f; // calculate the difference between x and 0x30-1
  int diff2 = 0x3a + ~x; // difference between 0x3a and x-1
  return !((diff1 >> 31) | (diff2 >> 31)); // checks if both of the differences are not negative
}


/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {\
  int diff = !(x>>31)^!(y>>31);   // Assigning 1 if x and y have different signs by checking the first digit of the binary
  int signOfx = diff & (x>>31);   // Assigning 1 if x is negative by checking the first digit of x's binary
  int subtract = y+(~x+1);    // Assigning y-x to check the sign after subtraction
  int signOfy = !diff & !(subtract>>31);    // Assigning 1 if x and y have the same signs and y-x is greater than equal to 0
  return signOfx | signOfy;   // Returning 1 if x is less than equal to y and returning 0 if both cases has value 0
}


/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  int flipped = x | (~x+1); // flip sign of x and or with x itself to get sign bit
  int signbit = flipped >>31; // get least significant bit
  int result = ~(signbit) & 1; // flip sign to check if it's non-zero or zero
  return result;
}


/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int y = x >> 31; // get the signed bit
  return (x+y) ^ y; // if x is positive, y will be 0 and will result in x ; if x is negative, y will be -1 and it will result in 2's complement of x
}