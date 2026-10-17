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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vvll g(2 * n);
    set<pll> s;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        s.insert({u, v});
        u--;
        v--;
        g[u].pb(v + n);
    }
    vb used(n);
    vll mt(2 * n, -1);
    auto kuhn_dfs = [&](this auto &kuhn_dfs, int v) -> bool {
        if (used[v])
            return false;
        used[v] = 1;
        each(to, g[v]) {
            if (mt[to] == -1 or kuhn_dfs(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    };
    int ans = 0;
    forn(v, n) {
        fill(all(used), 0);
        kuhn_dfs(v);
    }
    each(v, mt) {
        if (v != -1) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (int i = n; i < 2 * n; i++) {
        if (mt[i] != -1) {
            int a = i + 1, b = mt[i] + 1;
            if (a > n) {
                a -= n;
            }
            if (b > n) {
                b -= n;
            }
            cout << b << ' ' << a << '\n';
        }
    }
}
