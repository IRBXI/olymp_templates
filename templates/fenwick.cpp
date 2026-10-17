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

namespace ra = std::ranges;
namespace rv = std::ranges::views;

constexpr int N = 1e5;
array<ll, N + 1> t{};

ll sum(int r) {
    ll res = 0;
    for (; r > 0; r -= r & -r)
        res += t[r];
    return res;
}

// [l, r] 1 indexation
ll sum(int l, int r) { return sum(r) - sum(l - 1); }

// 1 indexation
void add(int n, int i, ll d) {
    for (; i <= n; i += i & -i)
        t[i] += d;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vll v(n);
    forn(i, n) {
        cin >> v[i];
        add(n, i + 1, v[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i++;
            ll w;
            cin >> w;
            ll d = w - v[i - 1];
            v[i - 1] = w;
            add(n, i, d);
        } else {
            int l, r;
            cin >> l >> r;
            l++;
            cout << sum(l, r) << '\n';
        }
    }
}

int main() {
    /*ifstream fileIn("input.txt");*/
    /*cin.rdbuf(fileIn.rdbuf());*/
    /*ofstream fileOut("output.txt");*/
    /*cout.rdbuf(fileOut.rdbuf());*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
