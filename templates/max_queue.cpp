struct max_stack {
    stack<pair<ll, ll>> s;

    void push(ll x) {
        if (s.empty()) {
            s.push({x, x});
            return;
        }
        s.push({x, max(s.top().S, x)});
    }

    ll mx() {
        if (s.empty()) {
            return LLONG_MIN;
        }
        return s.top().S;
    }

    ll pop() {
        if (s.empty()) {
            return 0;
        }
        ll e = s.top().F;
        s.pop();
        return e;
    }

    bool empty() { return s.empty(); }

    size_t size() { return s.size(); }
};

struct max_queue {
    max_stack head;
    max_stack tail;

    bool empty() { return head.empty() and tail.empty(); }

    void push(ll x) { tail.push(x); }

    void update() {
        while (!tail.empty()) {
            head.push(tail.pop());
        }
    }

    ll pop() {
        if (empty()) {
            return 0;
        }
        if (head.empty()) {
            update();
        }
        return head.pop();
    }

    ll mx() { return max(head.mx(), tail.mx()); }

    size_t size() { return head.size() + tail.size(); }
};
