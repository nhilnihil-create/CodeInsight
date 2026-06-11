#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n ,k;
    cin >> n >> k;
    int x[n];
    rep(i, n) cin >> x[i];
    int ans = 0;
    for (int i :x){
        ans += 2*min(i, abs(k-i));
    }
    cout << ans << endl;
}