const int N = 1e5;

array<vector<pi>, N> g;
array<int, N> s;
array<int, N> p;
array<int, N> tin;
array<int, N> tout;
array<int, N> head;
array<int, N - 1> edges;

segment_tree st(N);

int t = 0;

void sizes(int v = 0, int prev = 0) {
    s[v] = 1;
    forn(i, g[v].size()) {
        auto [to, w] = g[v][i];
        g[to].erase(find(all(g[to]), pi{v, w}));
        sizes(to, v);
        s[v] += s[to];
        if (s[to] > s[g[v][0][0]])
            swap(g[v][i], g[v][0]);
    }
}

int i = 0;

void hld(int v = 0, int prev = 0) {
    tin[v] = t++;
    eachp(to, w, g[v]) {
        head[to] = (to == g[v][0][0] ? head[v] : to);
        p[to] = v;
        edges[i++] = w;
        hld(to, v);
    }
    tout[v] = t;
}

int ancestor(int a, int b) { return tin[a] <= tin[b] && tin[b] < tout[a]; }

void up(int& a, int& b, int& ans, int x) {
    while (!ancestor(head[a], b)) {
        st.modify(tin[head[a]] - 1, tin[a], x);
        ans = add(ans, st.sum(tin[head[a]] - 1, tin[a]));

        a = p[head[a]];
    }
}

int get_sum(int a, int b, int x) {
    int ans = 0;

    up(a, b, ans, x);
    up(b, a, ans, x);

    if (!ancestor(a, b))
        swap(a, b);

    st.modify(tin[a], tin[b], x);

    ans = add(ans, st.sum(tin[a], tin[b]));
    return ans;
}
