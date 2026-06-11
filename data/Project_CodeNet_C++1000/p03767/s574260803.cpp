#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

using ll = long long;

int main() {
    int n;
    scanf("%d", &n);

    ll arr[3*n];
    for (int i = 0; i < 3*n; i ++)
        scanf("%lld", arr+i);

    sort(arr, arr+3*n);

    ll ans = 0;
    int idx = 3*n-1;
    while (n--) {
        idx --;
        ans += arr[idx];
        idx --;
    }

    printf("%lld\n", ans);

    return 0;
}

