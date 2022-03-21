/* 
 * <Frank Liu - fl2211>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*using the principles of boolean algebra we find that
 * x^y=(x&y)|(~x&~y)=~(x&y)&~(~x&~y)
 */
  return ~(x&y)&~(~x&~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
   //minimum two's complement integer is 10....00
   return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  /*when x is max int, x+1 = min int, and min int^max int = 111....1
 * x+!(x+1) helps distinguish max int from -1, as max int => min int, while -1 => -1
 * Thus in the end the statement converges to true if and only if x is max int
 */
  return !(~((x+!(x+1) )^ (x + 1)));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*0xAAAAAAAA is 1010....1010
    x&A can be used to isolate the odd-numbered bits
    ^A can be used to test if the two are equal.
    If x&A=0 all odd bits are 1, else they are not.
    Reverse with !.
  */
  int odd =  0xAA + (0xAA<<8) + (0xAA<<16) + (0xAA<<24); 
  return !((x&odd)^odd);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*Return two's complement*/
  return ~x+1;
}
//3
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
  //Check if x less than 0x30, or greater than 0x39 by checking sign bit after subtraction, 0x3a = 0x39+1
  return  !(((x+~0x30+1)|(0x3a+~x))>>31);
}
/* 
 * conditional -same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*Use x as a mask in order to cancel out one of the two elements depending on if x is zero or not
  */	 
  x = !x; //0 or 1
  //because of !, 0 -> y and 1 -> z
  x = (~x+1);//Either 1111....1 or 0000...0
  return (~x&y)+(x&z); //& to cancel one of the terms out
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* Need to account for overflow, if x and y are different sign, x can only be less if x is the negative
   * Otherwise, same sign, subtract x from y and check if negative, if is x is negative
   * Use !! to get into form of 0 or 1. 
   ~(~0u>>1) has  a bit representation of 1000..000 and can be used to test the sign bit.
  */ 
  int s = x^y; //same sign -> 0.....
  return !!(((s&x)|~(s|(y+~x+1)))&(1<<31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*Only Two's complement where the |
  return (((~x+1)|x)>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*x always need signed bit => implicit +1
 * Find position of highest non-sign bit, using binary search
* Find highest value that x can be shifted and remain non-zero 
*/
  int i = ~!(x>>31)+1;//Given that this is arithmetic shift we need to us ! to convert 1....0 to 00....01.
  int numbits = ~0;  
//negative numbers, each bit can represent 1 more value, so if negative go down 1 in positive representation, or use one's complement, then factor out the ~
  x = (i&x)+(~(i|x));
  i = 16;
  numbits += ~(~!(x>>(i+numbits))+1)&i;
  i = i>>1; //i = 8
  numbits += ~(~!(x>>(i+numbits))+1)&i;
  i = i>>1; //i = 4
  numbits += ~(~!(x>>(i+numbits))+1)&i;
  i = i>>1; //i = 2; 
  numbits += ~(~!(x>>(i+numbits))+1)&i;
  i = i>>1; //i = 1;
  numbits += ~(~!(x>>(i+numbits))+1)&i;
  return numbits+2;
}
//float
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
	/*Doubles the value of the float representation of uf 
 	*Does this through handling all possible encoding types
	*Infinity/NA returns the argument, If doublign makes it inifinity that is handled, 
	*if exponent is 0 in special encoding can simply left shift
        *Finally the base case of normal encoding where we can just add 1 to the 9th binary place
 	*/ 
	int exp = (uf<<1)>>24; //exp
	if(exp==0xFF) return uf;//0xFF = 11111111
	if(exp==0xFE) return (0xFF<<23)|(uf&(1<<31)); //If exponent = 1111 1110, 2x => infinity, so make infinity with sign rather than Nan 
	if(exp==0) return (uf<<1)|(uf&(1<<31)); //If the exponent is 0, return the left shift and the sign bit, we can see the overflow actually works out
	return uf+(1<<23);//base case
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
    /* Convert from an int to float representation
     * First find the parity, and then find the absolute value.
     * Then continue by finding the mantissa and exponent
     * Then check if rounding is needed
     * Add signbit, exp, and frac to get the float representation
    */
    int bit_mask= 1<<31; //signed bit mask
    int exp = 158; //31 +127
    int sign = x&bit_mask; //signed bit
    int frac;
    if (!x) //if x is equal to 0
        return 0;
    if (x == bit_mask) //min int causes over flow
        return bit_mask|(158<<23); //min int representation in float 
    if (sign)
        x = ~x + 1; //use absolute value
    //iterate through until most significant non-zero value is at the bit;
    while (!(x&bit_mask)) {
        x = x<< 1;
        exp--;
    }
    frac = (x&(~bit_mask)) >> 8;//move frac to correct position, note that sign bit is removed.
    if (x&0x80 && ((x&0x7F) > 0 || frac&1)) //Rounding if part lost in shifting x is non 0, else find closest, or if frac is odd.
        frac++;
    return sign + (exp<<23) + frac;
}
/*
unsigned float_i2f(int x) {
	#define bit_mask 0x80000000
	int exp = -1;
	int sign = x&bit_mask;
	if(!x) return x;			
	if (x == bit_mask)//min int causes overflow so must be handled	
        	return bit_mask | (158<<23);
	if(sign)
	    x=~x+1; //convert to positive
	//find the most significant bit needed to represent x (unsigned)
	int frac = 16; // use as index variable for now
	while(frac){
	   if(x>>(frac+exp)) exp+=frac; 
	   frac>>=1;
	}	
	x = x<<(32-exp);
	frac = x;
	frac = (frac&bit_mask)>>8;
	//check for rounding
	if (x&0x80 && ((x&0x7F) > 0 || frac&1)){
		frac=frac+1;
	}
	exp += 127;
	return sign+(exp<<23)+frac;
}*/
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	/* Converts from float to int, truncating decimal places
  	* Handles all three types of values in floats
	*/
	//bias = 12
	unsigned sign = uf>>31;
	unsigned exp = ((uf<<1)>>24)-127;
	//cannot do fractions
	if(exp&(1<<31)) return 0; // if exponent is less than 0 
	uf=uf&0x7FFFFF;
	if(exp>22){//shift mantissa according to exponent
		if(exp>30) return 0x80000000u; //out of range
		//calculate value
		if(sign) return ~((uf<<(exp-23))+(1<<exp))+1;
		return ((uf<<(exp-23))+(1<<exp));
	}
	//calculate value
	if(sign) return ~((uf>>(23-exp))+(1<<exp))+1;
	return ((uf>>(23-exp))+(1<<exp));
}
