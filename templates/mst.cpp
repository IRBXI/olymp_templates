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

struct segment_tree {
    vvi tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size - 1, {});
    }

    void build(vi& v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                tree[x] = vector<int>{
                    v[lx],
                };
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, x * 2 + 1, lx, m);
        build(v, x * 2 + 2, m, rx);
        merge(all(tree[x * 2 + 1]), all(tree[x * 2 + 2]),
              back_inserter(tree[x]));
    }

    void build(vi& v) {
        init(v.size());
        build(v, 0, 0, size);
    }

    int get(int l, int r, int w, int x, ll lx, ll rx) {
        if (lx >= r or l >= rx) {
            return INT_MAX;
        }
        if (lx >= l and rx <= r) {
            auto lower = lower_bound(all(tree[x]), w);
            if (lower == tree[x].end()) {
                return INT_MAX;
            }
            return *lower;
        }
        int m = (lx + rx) / 2;
        return min(get(l, r, w, x * 2 + 1, lx, m),
                   get(l, r, w, x * 2 + 2, m, rx));
    }

    int get(int l, int r, int w) { return get(l, r, w, 0, 0, size); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
