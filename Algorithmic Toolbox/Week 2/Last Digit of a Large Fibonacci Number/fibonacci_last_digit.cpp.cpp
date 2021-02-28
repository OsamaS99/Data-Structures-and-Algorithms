#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n) {
    std::vector <long> arr(n + 1, 0);
    arr[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        arr[i] = arr[i - 1] % 10 + arr[i - 2] % 10;
    }
    return arr[n] % 10;
}

int main() {
    long n;
    std::cin >> n;
    long long  c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
