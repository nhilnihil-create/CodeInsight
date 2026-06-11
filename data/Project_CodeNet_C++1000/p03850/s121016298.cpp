#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;

char sign[100005];

int arr[100005];

ll sum, ans;

int n;

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            scanf(" %c", &sign[i]);
        }
        else {
            sign[i] = '+';
        }

        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; ++i) {
        sum += arr[i];
    }

    int ptr = 1;

    while (ptr <= n && sign[ptr] == '+') {
        ++ptr;
    }

    ll cur1 = 0, cur2 = 0;

    if (ptr > n) {
        ans = 0;
    }
    else {
        ans = 1e15;
    }

    for (; ptr <= n; ++ptr) {
        if (sign[ptr] == '-') {
            cur1 += arr[ptr];
            cur2 = 0;
        }
        else {
            cur2 += arr[ptr];
        }

        if (ptr == n || sign[ptr + 1] == '-') {
            ans = min(ans, cur1 + cur2);
        }
    }

    printf("%lld\n", sum - 2 * ans);
}

int main() {
    #ifdef BThero
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // BThero

    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}