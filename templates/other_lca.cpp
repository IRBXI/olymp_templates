#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i < (n); ++i)
#define fornn(i, n) for (int i = 0; i <= (n); ++i)
#define forn1n(i, n) for (int i = 1; i <= (n); ++i)
#define each(x, a) for (auto& x : a)
#define eachp(x, y, a) for (auto& [x, y] : a)
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vi d(n), p(n);
    int logn = ceil(log2(n));
    vvi up(n, vi(logn));
    auto lca = [&](int v, int u) {
        if (d[v] > d[u]) {
            swap(v, u);
        }
        for (int l = logn - 1; l >= 0; l--) {
            if (d[up[u][l]] - d[v] >= 0) {
                u = up[u][l];
            }
        }
        if (v == u) {
            return v;
        }
        for (int l = logn - 1; l >= 0; l--) {
            if (up[v][l] != up[u][l]) {
                v = up[v][l];
                u = up[u][l];
            }
        }
        return p[v];
    };
}
