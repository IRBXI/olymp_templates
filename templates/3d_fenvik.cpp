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

ll t[129][129][129];

int n;

ll sum(int r1, int r2, int r3) {
    ll res = 0;
    for (int i = r1; i > 0; i -= i & -i) {
        for (int j = r2; j > 0; j -= j & -j) {
            for (int k = r3; k > 0; k -= k & -k) {
                res += t[i][j][k];
            }
        }
    }
    return res;
}

void add(int r1, int r2, int r3, ll x) {
    for (int i = r1; i <= n; i += i & -i) {
        for (int j = r2; j <= n; j += j & -j) {
            for (int k = r3; k <= n; k += k & -k) {
                t[i][j][k] += x;
            }
        }
    }
}

ll sum3d(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sum(x2, y2, z2) - sum(x1, y2, z2) - sum(x2, y1, z2) -
           sum(x2, y2, z1) + sum(x2, y1, z1) + sum(x1, y2, z1) +
           sum(x1, y1, z2) - sum(x1, y1, z1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    forn(i, 129) {
        forn(j, 129) {
            forn(k, 129) { t[i][j][k] = 0; }
        }
    }
}
