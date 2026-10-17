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
    // starting point
    int s;
    gr g(n);
    vll d(n, 1e18);
    vb used(n);
    d[s] = 0;
    forn(i, n) {
        forn(v, n) {
            eachp(u, w, g[v]) {
                if (d[u] > d[v] + w) {
                    d[u] = d[v] + w;
                    if (i == n - 1 and used[u]) {
                        cout << "Negative cycle\n";
                        return 0;
                    }
                }
            }
        }
    }
}
