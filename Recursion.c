#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 1. Print numbers from 1 to N
void print1toN(int n) {
    if (n == 0) return;
    print1toN(n - 1);
    printf("%d ", n);
}

// 2. Print numbers from N to 1
void printNto1(int n) {
    if (n == 0) return;
    printf("%d ", n);
    printNto1(n - 1);
}

// 3. Sum of first N natural numbers
int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

// 4. Factorial of N
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 5. a^b (a raised to the power b)
int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

// 6. Nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 7. Sum of digits of a number
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// 8. Check if string is palindrome
bool isPalindrome(char s[], int start, int end) {
    if (start >= end) return true;
    if (s[start] != s[end]) return false;
    return isPalindrome(s, start + 1, end - 1);
}

// 9. Reverse a string using recursion
void reverseString(char s[], int start, int end) {
    if (start >= end) return;
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverseString(s, start + 1, end - 1);
}

// 10. Count number of digits
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

// 11. Count zeros in a number
int countZeros(int n) {
    if (n == 0) return 0;
    return (n % 10 == 0 ? 1 : 0) + countZeros(n / 10);
}

// 12. Check if number is prime
bool isPrime(int n, int i) {
    if (n <= 2) return (n == 2);
    if (n % i == 0) return false;
    if (i * i > n) return true;
    return isPrime(n, i + 1);
}

// 13. Sum of elements in array
int sumArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[0] + sumArray(arr + 1, n - 1);
}

// 14. Max element in array
int maxInArray(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxRest = maxInArray(arr + 1, n - 1);
    return (arr[0] > maxRest) ? arr[0] : maxRest;
}

// ==============================
// you can test any function here by changing it
// ==============================
int main() {
    printf("Factorial of 5: %d\n", factorial(5));

    int arr[] = {1, 2, 3, 10, 4};
    printf("Sum of array: %d\n", sumArray(arr, 5));

    char name[] = "madam";
    printf("Is '%s' palindrome? %s\n", name,
           isPalindrome(name, 0, strlen(name) - 1) ? "Yes" : "No");

    return 0;
}
