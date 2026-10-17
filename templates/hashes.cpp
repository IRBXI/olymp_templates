#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i < (n); ++i)
#define fornn(i, n) for (int i = 0; i <= (n); ++i)
#define forn1n(i, n) for (int i = 1; i <= (n); ++i)
#define each(x, a) for (auto &x : a)
#define eachp(x, y, a) for (auto &[x, y] : a)
#define pb push_back
#define F first
#define S second

using ll = long long;
using ull = unsigned long long;
using vb = vector<char>;
using vvb = vector<vector<char>>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using str = string;
using pi = array<int, 2>;
using pll = array<ll, 2>;
using vpi = vector<pi>;
using vpll = vector<pll>;
using gr = vector<vector<pll>>;

const ll k = 31;
const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        n >>= 1;
    }
    return res;
}

ll inv(ll x) { return bin_pow(x, MOD - 2); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vll p(1e6 + 1);
    p[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        p[i] = p[i - 1] * k % MOD;
    }
    string s;
    cin >> s;
    int n = s.size();
    vll h_s(n + 1), rev_h_s(n + 1);
    for (int i = 1; i <= n; i++) {
        h_s[i] = h_s[i - 1] + ((s[i - 1] - 'a' + 1) * p[i - 1]) % MOD;
        h_s[i] %= MOD;
        rev_h_s[i] = rev_h_s[i - 1] + ((s[i - 1] - 'a' + 1) * p[n - i]) % MOD;
        rev_h_s[i] %= MOD;
    }
    auto substr_hash = [&](int l, int r) {
        ll res = h_s[r] - h_s[l];
        if (res < 0) {
            res += MOD;
        }
        return res * inv(p[l]) % MOD;
    };
    auto rev_substr_hash = [&](int l, int r) {
        ll res = rev_h_s[r] - rev_h_s[l];
        if (res < 0) {
            res += MOD;
        }
        return res * inv(p[n - r]) % MOD;
    };
}
