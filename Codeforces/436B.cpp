#include <bits/stdc++.h>
using namespace std;

bool check[26];

void clear() {
    for (int i = 0; i < 26; i++) {
        check[i] = false;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[205];
    scanf("%s", s);
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            clear();
            temp = 0;
        } else {
            if (!check[s[i] - 'a']) {
                temp++;
                check[s[i] - 'a'] = true;
                ans = max(ans, temp);
            }
        }
    }
    printf("%d\n", ans);
}
