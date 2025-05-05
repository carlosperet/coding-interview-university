#include "bitwise.h"

int main(void) {
	int num = -100;
	printf("%u\n", Abs(num));
	printf("The min is: %d\n", Min(10, 50));
	printf("The max is: %d\n", Max(10, 50));
}

unsigned int Abs(int val) {
	int const mask = val >> (sizeof(int) * CHAR_BIT -1);
	
	return (val + mask) ^ mask;
}

int Min(int a, int b) {
	return a^((b ^ a) & -(b < a));
}

int Max(int a, int b) {
	return b ^((b ^ a) & -(b < a));
}

bool PowOf2(int val) {
	return val && (val & (val-1));
}
unsigned int Modify_bits(const unsigned int value, const unsigned int mask,  bool flag) {

}
