struct min_stack {
    stack<pair<int, int>> s;

    void push(int x) {
        if (s.empty()) {
            s.push({x, x});
            return;
        }
        s.push({x, min(s.top().S, x)});
    }

    int mn() {
        if (s.empty()) {
            return INT_MAX;
        }
        return s.top().S;
    }

    int pop() {
        if (s.empty()) {
            return 0;
        }
        int e = s.top().F;
        s.pop();
        return e;
    }

    bool empty() { return s.empty(); }
};

struct min_deque {
    min_stack head;
    min_stack tail;

    bool empty() { return head.empty() and tail.empty(); }

    void push_front(int x) { head.push(x); }
    void push_back(int x) { tail.push(x); }

    void update() {
        if (head.empty()) {
            int f = tail.s.size() / 2;
            stack<int> l;
            forn(i, f) { l.push(tail.pop()); }
            while (!tail.empty()) {
                head.push(tail.pop());
            }
            while (!l.empty()) {
                tail.push(l.top());
                l.pop();
            }
        } else if (tail.empty()) {
            int f = head.s.size() / 2;
            stack<int> l;
            forn(i, f) { l.push(head.pop()); }
            while (!head.empty()) {
                tail.push(head.pop());
            }
            while (!l.empty()) {
                head.push(l.top());
                l.pop();
            }
        }
    }

    int pop_front() {
        if (empty()) {
            return 0;
        }
        if (head.empty()) {
            update();
        }
        return head.pop();
    }

    int pop_back() {
        if (empty()) {
            return 0;
        }
        if (tail.empty()) {
            update();
        }
        return tail.pop();
    }

    int mn() { return min(head.mn(), tail.mn()); }
};
