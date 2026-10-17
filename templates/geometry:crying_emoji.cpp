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

typedef double T;

const T PI = acosl(-1);
const T EPS = 1e-6;

struct pt {
    T x, y;
    friend istream &operator>>(istream &in, pt &a) {
        in >> a.x >> a.y;
        return in;
    }
    friend ostream &operator<<(ostream &out, pt &a) {
        cout << a.x << ' ' << a.y << '\n';
        return out;
    }
    friend bool operator==(pt a, pt b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(pt a, pt b) { return !(a == b); }
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(T d) { return {x * d, y * d}; }
    pt operator/(T d) { return {x / d, y / d}; }
    friend T sq(pt p) { return p.x * p.x + p.y * p.y; }
    friend double abs(pt p) { return sqrt(sq(p)); }
    friend T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
    friend T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }
    friend pt norm(pt p) { return p / abs(p); }
};
struct line {
    pt v;
    T c;
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
    T side(pt p) { return cross(v, p) - c; }
    double distPoint(pt p) { return abs(side(p)) / abs(v); }
    bool cmpProj(pt p, pt q) { return dot(v, p) < dot(v, q); }
};

void sortPolar(vector<pt> &v) {
    sort(v.begin(), v.end(), [](pt a, pt b) {
        return cross({1, 0}, norm(a)) > cross({1, 0}, norm(b));
    });
}

T get_polygon_area(vector<pt> &v) {
    T area = 0.0;
    for (int i = 0; i < v.size(); i++) {
        pt p1, p2;
        if (i == 0) {
            p1 = v.back();
        } else {
            p1 = v[i - 1];
        }
        p2 = v[i];
        area += (p1.x - p2.x) * (p1.y + p2.y) / 2.0;
    }
    return abs(area);
}

T distSegPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.distPoint(p);
    }
    return min(abs(p - a), abs(p - b));
}

T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

bool inDisk(pt a, pt b, pt p) { return dot(a - p, b - p) <= 0; }

bool onSegment(pt a, pt b, pt p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

bool areIntersecting(pt a, pt b, pt c, pt d) {
    T n1 = cross((b - a), (c - a));
    T n2 = cross((b - a), (d - a));
    T n3 = cross((d - c), (a - c));
    T n4 = cross((d - c), (b - c));
    if (n1 * n2 < 0 and n3 * n4 < 0) {
        return true;
    }
    if (onSegment(c, d, a)) {
        return true;
    }
    if (onSegment(c, d, b)) {
        return true;
    }
    if (onSegment(a, b, c)) {
        return true;
    }
    if (onSegment(a, b, d)) {
        return true;
    }
    return false;
}

T SegDist(pt a, pt b, pt c, pt d) {
    if (areIntersecting(a, b, c, d)) {
        return 0;
    }
    return min({distSegPoint(a, b, c), distSegPoint(a, b, d),
                distSegPoint(c, d, a), distSegPoint(c, d, b)});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
