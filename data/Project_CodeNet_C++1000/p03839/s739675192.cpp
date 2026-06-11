#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll pre[100005];
ll pos[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pre[i] = pre[i-1] + x;
        pos[i] = pos[i-1];
        if(x >= 0) pos[i] += x;
    }
    ll res = 0;
    for(int l=1; l+k-1<=n; l++){
        int r = l+k-1;
        ll sum = pre[r] - pre[l-1];
        ll gre = pos[r] - pos[l-1];
        res = max(res, max(0LL, sum) + pos[n]-gre);
    }
    cout << res;
    return 0;
}
