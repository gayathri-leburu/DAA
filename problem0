fib(5)
    fib(4)
        fib(3)
            fib(2)
                fib(1)
                    return 1
                fib(0)
                    return 0
                return 1 + 0 = 1
            fib(1)
                return 1
            return 1 + 1 = 2
        fib(2)
            fib(1)
                return 1
            fib(0)
                return 0
            return 1 + 0 = 1
        return 2 + 1 = 3
    fib(3)
        fib(2)
            fib(1)
                return 1
            fib(0)
                return 0
            return 1 + 0 = 1
        fib(1)
            return 1
        return 1 + 1 = 2
    return 3 + 2 = 5
***********************************************************************************************************
The call stack would look like as follows:

    fib(5) -> fib(4) -> fib(3) -> fib(2) -> fib(1)
                |          |        -> fib(0)
                |          -> fib(1)
                -> fib(3) -> fib(2) -> fib(1)
                           |        -> fib(0)
                           -> fib(1)
***********************************************************************************************************


#include <stdio.h>

int fib(int n);

int main() {
    int result = fib(5);
    printf("Fibonacci(5) = %d\n", result);
    return 0;
}

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
