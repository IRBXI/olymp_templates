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
    // m log m
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    vvll edges1(m, vll(3));
    forn(i, m) {
        ll u, v;
        cin >> u >> v;
        ll w;
        cin >> w;
        edges1[i] = {w, u, v};
    }
    sort(all(edges1));
    vi p(n), s(n, 1);
    iota(all(p), 0);
    function<int(int)> find_set;
    find_set = [&](int v) {
        if (v == p[v]) {
            return v;
        }
        return p[v] = find_set(p[v]);
    };
    auto union_sets = [&](int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return;
        }
        if (s[a] < s[b]) {
            swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
    };
    ll ans1 = 0;
    forn(i, m) {
        int a = find_set(edges1[i][1] - 1);
        int b = find_set(edges1[i][2] - 1);
        if (a == b) {
            continue;
        }
        ans1 += edges1[i][0];
        union_sets(a, b);
    }
}
