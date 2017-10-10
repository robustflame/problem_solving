#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int n;
int a[MAX_N];
int cnt[MAX_N];
bool must[MAX_N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    deque<int> unused;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            unused.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] > 1) {
            if (a[i] <= unused.front() && !must[a[i]]) {
                must[a[i]] = true;
            } else {
                cnt[a[i]]--;
                a[i] = unused.front();
                unused.pop_front();
                cnt[a[i]]++;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}
