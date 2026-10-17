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

const int B = 448;

struct query {
    int l, r, i;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vi v(n);
    forn(i, n) { cin >> v[i]; }
    vector<query> b[B];
    forn(i, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        b[l / B].pb({l, r, i});
    }
    forn(i, B) {
        sort(all(b[i]), [](query &a, query &b) { return a.r < b.r; });
    }
    vi cnt(2e5 + 1);
    vi ans(q);
    int res;

    auto add = [&](int i) { res += cnt[v[i]]++ == 0; };
    auto del = [&](int i) { res -= --cnt[v[i]] == 0; };
    forn(i, B) {
        int l = i * B, r = i * B - 1;
        res = 0;
        memset(&cnt[0], 0, sizeof(int) * (2e5 + 1));
        for (auto [L, R, idx] : b[i]) {
            while (r < R) {
                add(++r);
            }
            while (l < L) {
                del(l++);
            }
            while (l > L) {
                add(--l);
            }
            ans[idx] = res;
        }
    }
    forn(i, q) { cout << ans[i] << '\n'; }
}
