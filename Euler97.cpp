#include <iostream>

constexpr long long MOD = 10000000000LL;

long long mul_mod(long long a, long long b) {
    return (__int128)a * b % MOD;
}

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = mul_mod(result, base);

        base = mul_mod(base, base);
        exp /= 2;
    }

    return result;
}

int main() {
    long long ans = (mul_mod(28433, mod_pow(2, 7830457)) + 1) % MOD;
    std::cout << ans << std::endl;
}
