#include <iostream>
#include <vector>
#include <algorithm>

constexpr int LIMIT = 100000000;
constexpr int PRIME_LIMIT = LIMIT / 2;

int main() {
    std::vector<bool> is_prime(PRIME_LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; 1LL * i * i <= PRIME_LIMIT; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= PRIME_LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= PRIME_LIMIT; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    long long ans = 0;

    for (std::size_t i = 0; i < primes.size(); ++i) {
        int p = primes[i];
        int max_q = (LIMIT - 1) / p;

        auto it = std::upper_bound(primes.begin() + i, primes.end(), max_q);
        ans += (it - (primes.begin() + i));
    }

    std::cout << ans << '\n';
    return 0;
}
