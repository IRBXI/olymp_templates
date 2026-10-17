
constexpr int logn = 20;

int main() {
    int n;
    vi v(n);
    array<vi, logn> mx;
    forn(i, logn) { mx[i].assign(n, INT_MIN); }
    auto build = [n](array<vi, logn>& mx, const vi& v) {
        mx[0] = v;
        for (int l = 0; l < logn - 1; l++)
            for (int i = 0; i + (2 << l) <= n; i++)
                mx[l + 1][i] = max(mx[l][i], mx[l][i + (1 << l)]);
    };
    auto rmq = [](const array<vi, logn>& mx, int l, int r) {
        int t = __lg(r - l);
        return max(mx[t][l], mx[t][r - (1 << t)]);
    };
}
