vi compress(vi& a) {
    vi b = a;

    ra::sort(b);

    b.erase(unique(all(b)), b.end());

    for (int& x : a) {
        x = int(ra::lower_bound(b, x) - b.begin());
    }

    return b;
}
