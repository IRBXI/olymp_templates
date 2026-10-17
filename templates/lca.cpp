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
    int root;
    int t = 0;
    vvll g(n);
    int logn = ceil(log2(n));
    vvi up(n, vi(logn));
    vi tin(n), tout(n);
    vb used(n);
    up[root][0] = root;
    function<void(int)> lca_dfs;
    lca_dfs = [&](int v) {
        forn1(l, logn) { up[v][l] = up[up[v][l - 1]][l - 1]; }
        used[v] = 1;
        tin[v] = t++;
        each(to, g[v]) {
            if (!used[to]) {
                up[to][0] = v;
                lca_dfs(to);
            }
        }
        tout[v] = t;
    };
    lca_dfs(root);
    auto is_pred = [&](int u, int v) {
        return tin[v] >= tin[u] && tin[v] < tout[u];
    };
    auto lca = [&](int v, int u) {
        if (is_pred(v, u)) {
            return v;
        }
        if (is_pred(u, v)) {
            return u;
        }
        for (int l = logn - 1; l >= 0; l--) {
            if (!is_pred(up[v][l], u)) {
                v = up[v][l];
            }
        }
        return up[v][0];
    };
}
