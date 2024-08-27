/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
  NAME : UDAY SANKAR GOTTIPALLI
  ROLL NUMBER: 24210108
 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Instructions to Students:

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  long Funct(long arg1, long arg2, ...) {
      // brief description of how your implementation works
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  2. Function arguments and local variables (no global variables).
  3. Local variables of type int and long
  4. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  5. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  6. Casting from int to long and from long to int

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  //
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
  //
  long pow2plus1(long x) {
     // exploit ability of shifts to compute powers of 2
     // Note that the 'L' indicates a long constant
     return (1L << x) + 1L;
  }

  //
  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
  //
  long pow2plus4(long x) {
     // exploit ability of shifts to compute powers of 2
     long result = (1L << x);
     result += 4L;
     return result;
  }

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

CAUTION:
  Do not add an #include of <stdio.h> (or any other C library header)
  to this file.  C library headers almost always contain constructs
  that dlc does not understand.  For debugging, you can use printf,
  which is declared for you just below.  It is normally bad practice
  to declare C library functions by hand, but in this case it's less
  trouble than any alternative.

  dlc will consider each call to printf to be a violation of the
  coding style (function calls, after all, are not allowed) so you
  must remove all your debugging printf's again before submitting your
  code or testing it with dlc or the BDD checker.  */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 2
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Examples:
 *     copyLSB(5L) = 0xFFFFFFFFFFFFFFFFL,
 *     copyLSB(6L) = 0x0000000000000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long copyLSB(long x) {
/* 
  find the LSB
  negate LSB and add 1
*/
    
    long lsb = x & 1;
    long copylsb = ~lsb + 1;
    
    return copylsb;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples: allOddBits(0xFFFFFFFDFFFFFFFDL) = 0L,
 *             allOddBits(0xAAAAAAAAAAAAAAAAL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long allOddBits(long x) {
/* 
  create a mask for all odd position bits 101010.....,
  consider only the odd position bits from x
  use xor operator to check if they are equal
  
*/
    long oddbits_1 = 0xAA;
    oddbits_1 = (oddbits_1 << 8) | oddbits_1;
    oddbits_1 = (oddbits_1 << 16) | oddbits_1;
    oddbits_1 = (oddbits_1 << 32) | oddbits_1;
    
    long oddbits_x = x & oddbits_1;
    
    // using the bitwise 'xor' operator will return 0, if bits in same position is same and non zero otherwise
    long oddbits_xor = oddbits_x ^ oddbits_1;
    
    // negating the oddbits_xor will return 1 is all odd numbered bits in word set to 1, otherwise 0
    long alloddbits = !oddbits_xor;
    return alloddbits;
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5L, 5L) = 0L, isNotEqual(4L, 5L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
long isNotEqual(long x, long y) {
/* 
xor operator can be used to check if two number are equal
*/
    long xor = x ^ y;

    return !(!xor);
}
/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {
/* 
  quotient is x except for last n bits
  if sign is negative, add 1 to the quotient
*/
    long quotient = x >> n;
    long n_ones = (1L << n) + ~0L;
    long sign = x >> 63;
    long remainder = x & n_ones;
    long add_1 = (sign & (!(!remainder)));

    return quotient + add_1;
}
// 3
/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15L,2L) = 3, remainderPower2(-35L,3L) = -3L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long remainderPower2(long x, long n) {
/* 
  remainder = n LSB bits
  if remainder = 0, then return remainder
  if sign is positive, then return remainder
  if sign is negative, then return n bit 2's compliment of remainder
*/
    long mask = (1L << n) + ~0L;
    
    long rem = x & mask;
    
    long sign = x >> 63;
    
    long is_rem = !(!rem) ;
    is_rem = (is_rem << 63) >> 63; 
    return is_rem & ((sign & (~((1L << n) + ~rem + 1) + 1)) | ((~sign) & rem) );
    //return is_rem & ((sign & rem) | ((~sign) & rem) );
    
    
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
/* 
  copy the n MSB bits from x and bring them to LSB
  rotate x by n bits
  add above two  numbers
*/
    long leftmask = (1L << n) + ~0L;
    long temp = (64 + ~n + 1);
    leftmask = leftmask << temp;
    
    long left = x & leftmask;
    x = x << (n);
    
    long sign = left >> 63;
    sign = sign << n;
    
    left = left >> temp;
    long right =  left ^ sign;
    
    return x | right;
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   between lowbit and highbit
 *   Examples: bitMask(5L,3L) = 0x38L
 *   Assume 0 <= lowbit < 64, and 0 <= highbit < 64
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long bitMask(long highbit, long lowbit) {
/* 
  divide x by 4 using >> 2 operator.
  store the overflow.
  multiply the result with 2 by using the << 1 and use the overflow bits
  add the same value to the result.
*/
    long highbit1 = highbit >> 1L;
    highbit1 = highbit1 << 1;
    long highbit2 = highbit & 1L;
    long temp = ~0L;
    long high_mask1 = (1L << (highbit1+1)) + temp;
    high_mask1 = high_mask1 << highbit2;
    long high_mask2 = (1L << highbit2) + temp;
    long high_mask = high_mask1 | high_mask2;
    long low_mask = (1L << lowbit) + temp;
    
    long result_mask = high_mask & ~low_mask;
    
    
    return result_mask;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5L) = 0L, isPower2(8L) = 1L, isPower2(0) = 0L
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long isPower2(long x) {
/* 
  for a number to be power of 2 it should satisfy the three conditions
  1. should be positive
  2. should be non zero
  3. should contain only one 1 and followed zeroes => x & (x-1) = 0
*/
    long is_positive = ~((x >> 63) & 1);
    
    long is_not_zero = !(!(x & ~0L));
    
    long is_power_of_2 = !(x & (x + ~0L));
    
    return is_positive & is_power_of_2 & is_not_zero;
}
// 4
/*
 * allAsciiDigits - return 1 if each byte b in x satisfies
 *   0x30 <= b <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: allAsciiDigits(0x3031323536373839L) = 1L.
 *            allAsciiDigits(0x4031323536373839L) = 0L.
 *            allAsciiDigits(0x0031323536373839L) = 0L.
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 4
 */
long allAsciiDigits(long x) {
/* 
  compare each byte as two nibbles.
  upper nibble of each byte contains 3,
  lower nibble of each satisfies the condition for n4 n3 n2 n1, 
  (n3 | n2) & n4 should be 0
*/
    long lb = 0x0FL;
    lb = (lb << 8) | lb;
    lb = (lb << 16) | lb;
    lb = (lb << 32) | lb;
    
    long ub = (lb << 4);
    
    lb = x & lb;
    
    long lb1 = 0x02L;
    lb1 = (lb1 << 8) | lb1;
    lb1 = (lb1 << 16) | lb1;
    lb1 = (lb1 << 32) | lb1;
    long lb2 = lb1 >> 1;
    long ub1 = (lb1 | lb2) << 4;
    
    long c = lb & lb1;
    long c1 = (lb & (lb1 << 1)) | (c << 1);
    long c2 = lb & (c1 << 1);
    long ubc = (x & ub) ^ ub1;
    
    return !(ubc | c2);
    
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no
 * overflow) Legal ops: ! ~ & ^ | + << >> Max ops: 20 Rating: 4
 */
long trueThreeFourths(long x) {
/* 
  divide x by 4 using >> 2 operator.
  store the overflow.
  multiply the result with 2 by using the << 1 and use the overflow bits
  add the same value to the result.
*/

    long m1= (x & 0x3L);
    long m = (((m1 >> 1) << 63) >> 63) & m1;
    long is_rem = !(!m1);
    long sign = (x >> 63) & 0x1L;
    long plus_1 = ((is_rem << 63) >> 63) & sign;
    long x2 = x >> 2;
    long x1 = (x2 << 1);
    x1 = x1 | (m >> 1);
    m = m & 0x1L;
    x = x1 + x2 + m;
    
    return x + plus_1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5L) = 2, bitCount(7L) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
long bitCount(long x) {
/* based on the masks 010101..., 00110011..., and 00001111 count the number of bits that are 1.
  count all the values and shift them to the last 9 bits, which will be from 0 to 127 values output.
*/
  
    long m1 = 0x55L;
    m1 = (m1 << 8) | m1;
    m1 = (m1 << 16) | m1;
    m1 = (m1 << 32) | m1;
    long m2 = 0x33L;
    m2 = (m2 << 8) | m2;
    m2 = (m2 << 16) | m2;
    m2 = (m2 << 32) | m2;
    long m3 = 0x0FL;
    m3 = (m3 << 8) | m3;
    m3 = (m3 << 16) | m3;
    m3 = (m3 << 32) | m3;
    
    
    x = x  + (~((x >> 1) & m1) + 1);
    x = (x & m2) + ((x >> 2) & m2);
    x = (x  + (x >> 4)) & m3;
    x = x + (x >> 8);
    x = x  + (x >> 16); 
    x = x  + (x >> 32);
    
    return x & 0X7FL;
}
