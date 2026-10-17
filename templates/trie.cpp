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
const int k = 2;

struct V {
    V* to[k] = {0, 0};
    int t = 0;
};

V* root = new V();

vll get_bin(ll n) {
    vll res;
    while (n) {
        res.pb(n % 2);
        n /= 2;
    }
    while (res.size() != 32) {
        res.pb(0);
    }
    reverse(all(res));
    return res;
}

void add_num(ll n, int i) {
    vll bin = get_bin(n);
    /*forn(i, bin.size()) { cout << bin[i]; }*/
    /*cout << '\n';*/
    V* v = root;
    each(c, bin) {
        if (!v->to[c]) {
            v->to[c] = new V();
        }
        v = v->to[c];
        v->t++;
    }
}

ll get_max_xor(ll n, int i) {
    vll bin = get_bin(n);
    vll ans;
    V* v = root;
    each(c, bin) {
        if (v->to[(c + 1) % 2] and v->to[(c + 1) % 2]->t != 0) {
            ans.pb(1);
            v = v->to[(c + 1) % 2];
        } else if (v->to[c] and v->to[c]->t != 0) {
            ans.pb(0);
            v = v->to[c];
        } else {
            break;
        }
    }
    /*each(v, ans) { cout << v; }*/
    /*cout << '\n';*/
    ll ans1 = 0;
    ll n_2 = pow(2, 31);
    each(c, ans) {
        ans1 += n_2 * c;
        n_2 /= 2;
    }
    return ans1;
}

void erase(ll n) {
    vll bin = get_bin(n);
    V* v = root;
    each(c, bin) {
        v = v->to[c];
        v->t--;
    }
}

ll get_min_xor(ll n, int i) {
    vll bin = get_bin(n);
    vll ans;
    V* v = root;
    each(c, bin) {
        if (v->to[c] and v->to[c]->t != 0) {
            ans.pb(0);
            v = v->to[c];
        } else if (v->to[(c + 1) % 2] and v->to[(c + 1) % 2]->t != 0) {
            ans.pb(1);
            v = v->to[(c + 1) % 2];
        } else {
            break;
        }
    }
    /*each(v, ans) { cout << v; }*/
    /*cout << '\n';*/
    ll ans1 = 0;
    ll n_2 = pow(2, 31);
    each(c, ans) {
        ans1 += n_2 * c;
        n_2 /= 2;
    }
    return ans1;
}
