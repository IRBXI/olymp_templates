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
    struct node {
        node* l = nullptr;
        node* r = nullptr;
        ll sum;

        node(ll x) : sum(x) {}
    };
    using ptr = node*;

    ptr root = nullptr;
    ll n;

    inline ptr newnode(ll x) { return new node(x); }

    inline ll get(ptr node) { return !node ? 0 : node->sum; }

    segment_tree(ll n_) : n(n_) { root = newnode(0); }

    ptr modify(ptr cur, ll i, ll w, ll lx, ll rx) {
        if (cur == nullptr) {
            cur = newnode(0);
        }
        if (lx + 1 == rx) {
            cur->sum += w;
            return cur;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            cur->l = modify(cur->l, i, w, lx, m);
        } else {
            cur->r = modify(cur->r, i, w, m, rx);
        }
        cur->sum = get(cur->l) + get(cur->r);
        return cur;
    }

    void modify(ll i, ll w) { modify(root, i, w, 0, n); }

    ll sum(ptr cur, ll l, ll r, ll lx, ll rx) {
        if (cur == nullptr or lx >= r or l >= rx) {
            return 0;
        }
        if (lx >= l and rx <= r) {
            return cur->sum;
        }
        ll m = (lx + rx) / 2;
        ll res1 = sum(cur->l, l, r, lx, m);
        ll res2 = sum(cur->r, l, r, m, rx);
        return res1 + res2;
    }

    ll sum(ll l, ll r) { return sum(root, l, r, 0, n); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
