#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9 + 5;
const int MAX_M = 5e5 + 5;

struct Line {
    int id, a, b;

    Line(int id, int a, int b) : id(id), a(a), b(b) {}

    bool operator < (const Line& rhs) const {
        if (a != rhs.a) return a < rhs.a;
        return b > rhs.b;
    }
};

int n, m;
bool removed[MAX_M];

void cancel(vector<Line>& lines) {
    sort(lines.begin(), lines.end());
    int maxb = 0;
    for (auto& line : lines) {
        int id = line.id, b = line.b;
        if (b <= maxb) {
            removed[id] = true;
        }
        maxb = max(maxb, b);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    vector<Line> ga, gb;
    int mina_of_gb = n - 1;
    int maxb_of_gb = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b) {
            ga.emplace_back(i, a, b);
        } else {
            mina_of_gb = min(mina_of_gb, a);
            maxb_of_gb = max(maxb_of_gb, b);
            gb.emplace_back(i, a, b + n);
        }
    }
    for (auto& line : ga) {
        int id = line.id, a = line.a, b = line.b;
        if (b <= maxb_of_gb || a >= mina_of_gb) {
            removed[id] = true;
        }
    }
    cancel(ga);
    cancel(gb);
    for (int i = 1; i <= m; i++) {
        if (!removed[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
