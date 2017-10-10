#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, f, k;
    scanf("%lld %lld %lld %lld", &a, &b, &f, &k);
    long long ans = 0;
    long long cfuel = b;
    for (int i = 0; i < k - 1; i++) {
        if (i % 2 == 0) {
            if (cfuel >= 2 * a - f) {
                cfuel -= a;
            } else if (cfuel >= f && b >= a - f) {
                ans++;
                cfuel = b - (a - f);
            } else {
                printf("-1\n");
                return 0;
            }
        } else {
            if (cfuel >= a + f) {
                cfuel -= a;
            } else if (cfuel >= a - f && b >= f) {
                ans++;
                cfuel = b - f;
            } else {
                printf("-1\n");
                return 0;
            }
           
        }
    }
    if (k % 2) {
        if (cfuel >= a) {

        } else if (cfuel >= f && b >= a - f) {
            ans++;
        } else {
            printf("-1\n");
            return 0;
        }
    } else {
        if (cfuel >= a) {

        } else if (cfuel >= a - f && b >= f) {
            ans++;
        } else {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
}
