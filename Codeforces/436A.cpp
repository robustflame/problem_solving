#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        m[a]++;
    }
    if (m.size() == 2 && m.begin()->second == m.rbegin()->second) {
        printf("YES\n");
        printf("%d %d\n", m.begin()->first, m.rbegin()->first);
    } else {
        printf("NO\n");
    }
}
