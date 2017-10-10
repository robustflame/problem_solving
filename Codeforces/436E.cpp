#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int MAX_D = 2e3 + 50;

struct Item {
    int t, d, p, id;
    bool operator < (const Item& rhs) const {
        return d < rhs.d;
    }
};

int n;
Item items[MAX_N];
int dp[MAX_N][MAX_D];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &items[i].t, &items[i].d, &items[i].p);
        items[i].id = i + 1;
    }
    sort(items, items + n);
    for (int i = n - 1; i >= 0; i--) {
        for (int ct = 0; ct < MAX_D; ct++) {
            if (ct + items[i].t < items[i].d) {
                dp[i][ct] = max(dp[i][ct], dp[i+1][ct + items[i].t] + items[i].p);
            }
            dp[i][ct] = max(dp[i][ct], dp[i+1][ct]);
        }
    }
    vector<int> desired_set;
    int ct_temp = 0;
    for (int i = 0; i < n; i++) {
        if (ct_temp + items[i].t < items[i].d && dp[i][ct_temp] == dp[i+1][ct_temp + items[i].t] + items[i].p) {
            desired_set.push_back(items[i].id);
            ct_temp = ct_temp + items[i].t;
        }
    }
    printf("%d\n%d\n", dp[0][0], desired_set.size());
    for (int id : desired_set) {
        printf("%d ", id);
    }
    return 0;
}
