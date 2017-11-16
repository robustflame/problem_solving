#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9 + 5;
const int MAX_M = 5e5 + 5;
const int INF = 1e9;

struct Event {
    int x, y, id, type;

    Event(int x, int y, int id, int type) : x(x), y(y), id(id), type(type) {}

    bool operator < (const Event& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y > rhs.y;
    }
};

int n, m;
vector<Event> events;
bool covered[MAX_M];

int main() {
    scanf("%d %d", &n, &m);
    events.reserve(MAX_M * 2);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) {
            events.emplace_back(a, n + b, i, 0);
            events.emplace_back(n + b, a, i, 1);
        } else {
            events.emplace_back(a, b, i, 0);
            events.emplace_back(b, a, i, 1);
            events.emplace_back(n + a, n + b, i, 0);
            events.emplace_back(n + b, n + a, i, 1);
        }
    }
    sort(events.begin(), events.end());
    multiset<int> s;
    for (Event& p : events) {
        if (p.type) {
            multiset<int>::iterator it = s.find(p.y); 
            s.erase(it);
            if (!s.empty() && *s.begin() <= p.y) {
                covered[p.id] = true;
            }
        } else {
            s.insert(p.x);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!covered[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
