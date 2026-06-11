// Why am I so dumb? :c
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;   

int arr[7];

ll ans;

ll calc(int a, int b, int c) {
    ll ret = 0;

    ret += (b / 2) * 2;
    ret += (c / 2) * 2;
    ret += (a / 2) * 2;

    return ret;
}

void solve() {                       
    for (int i = 0; i < 7; ++i) {
        scanf("%d", &arr[i]);
    }    
    
    ans = calc(arr[0], arr[3], arr[4]);

    if (arr[3] > 0 && arr[4] > 0 && arr[0] > 0) {
        ans = max(ans, calc(arr[0] - 1, arr[3] - 1, arr[4] - 1) + 3);
    }   
          
    printf("%lld\n", ans + arr[1]);
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}