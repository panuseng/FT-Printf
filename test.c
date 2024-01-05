#include <stdio.h>
#include <stdarg.h>

int add_nums_C99(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count); // count can be omitted since C23

    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
		printf("%d \n", result);
    }

    va_end(args);
    return result;
}

int main(void)
{
    printf("%d\n", add_nums_C99(4, 25, 25, 50, 50));
}
