#include <stdio.h>
#include <unistd.h>

int main ()
{
	long num = -2147483649;
	if (num < -2147483648 || num > 2147483647) {
        // Print error message and return 1
        write(1, "error\n", 6); // Note: "error\n" instead of "erropr"
        return 1;
    }
}