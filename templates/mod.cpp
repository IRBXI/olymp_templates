#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <int MOD>
struct ModInt;

template <int MOD>
ModInt<MOD> bin_pow(ModInt<MOD> a, ll n) {
    ModInt<MOD> res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

template <int MOD>
inline ModInt<MOD> inv(ModInt<MOD> a) {
    return bin_pow<MOD>(a, MOD - 2);
}

template <int MOD>
struct ModInt {
    int x;

    ModInt() noexcept : x(0) {}

    ModInt(int n) noexcept : x(n % MOD) {}

    inline ModInt& operator+=(ModInt other) noexcept {
        x += other.x;
        x %= MOD;
        return *this;
    }

    inline ModInt operator+(ModInt other) noexcept {
        ModInt res(x);
        res += other;
        return res;
    }

    inline ModInt& operator++() noexcept {
        *this += 1;
        return *this;
    }

    inline ModInt operator++(int) noexcept {
        ModInt temp = *this;
        ++(*this);
        return temp;
    }

    inline ModInt& operator-=(ModInt other) noexcept {
        *this += MOD - other.x;
        return *this;
    }

    inline ModInt operator-(ModInt other) noexcept {
        ModInt res(x);
        res -= other;
        return res;
    }

    inline ModInt& operator*=(ModInt other) noexcept {
        x = (x * 1ll * other.x) % MOD;
        return *this;
    }

    inline ModInt operator*(ModInt other) noexcept {
        ModInt res(x);
        res *= other;
        return res;
    }

    inline ModInt& operator/=(ModInt other) noexcept {
        *this *= inv<MOD>(other);
        return *this;
    }

    inline ModInt operator/(ModInt other) noexcept {
        ModInt res(x);
        res /= other;
        return res;
    }

    friend ostream& operator<<(ostream& os, ModInt mi) {
        os << mi.x;
        return os;
    };
};

template <int MOD, int N>
struct Fact {
    using mi = ModInt<MOD>;
    array<mi, N> fact;

    Fact() noexcept {
        fact[0] = mi(1);
        for (int i = 1; i < N; i++) {
            fact[i] = fact[i - 1] * mi(i);
        }
    }

    inline mi C(int n, int k) {
        if (k > n) {
            return 0;
        }
        return fact[n] / (fact[n - k] * fact[k]);
    }
};

constexpr int N = 2e5;

constexpr int MOD = 1e9 + 7;

using mi = ModInt<MOD>;

Fact<MOD, N + 1> fact;
