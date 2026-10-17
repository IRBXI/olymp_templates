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
    int n;
    gr g(n);
    map<pi, int> mp1; // count of edges {v, u}
    vb used(n);
    vi tin(n);
    vi up(n);
    ll t = 0;
    vi bridges;
    function<void(int, int)> dfs;
    dfs = [&](int v, int prev) {
        used[v] = 1;
        tin[v] = up[v] = t++;
        eachp(to, i, g[v]) {
            if (to == prev) {
                continue;
            }
            if (used[to]) {
                up[v] = min(up[v], tin[to]);
            } else {
                dfs(to, v);
                up[v] = min(up[v], up[to]);
                if (up[to] > tin[v]) {
                    if (mp1[{v, (int)to}] == 1) {
                        bridges.pb(i);
                    }
                }
            }
        }
    };
    dfs(0, -1);
}
