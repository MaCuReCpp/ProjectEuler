#include <iostream>
#include <vector>
#include <cmath>

constexpr int LIMIT = 100'000'000;

std::vector<bool> make_sieve(int n) {
    std::vector<bool> prime(n + 1, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (prime[i]) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    return prime;
}

bool is_prime_generating(int n, const std::vector<bool>& prime) {
    for (int d = 1; 1LL * d * d <= n; ++d) {
        if (n % d == 0) {
            int other = n / d;

            if (!prime[d + other]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    auto prime = make_sieve(LIMIT + 1);

    long long sum = 0;

    // n = 1은 조건 만족: 1 + 1 / 1 = 2
    if (is_prime_generating(1, prime)) {
        sum += 1;
    }

    // n > 1이면 n + 1이 소수여야 한다.
    // n + 1이 홀수 소수라면 n은 짝수.
    for (int n = 2; n <= LIMIT; n += 2) {
        if (!prime[n + 1]) {
            continue;
        }

        if (is_prime_generating(n, prime)) {
            sum += n;
        }
    }

    std::cout << sum << '\n';
}
