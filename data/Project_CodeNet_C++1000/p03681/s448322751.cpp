/**
*    author:  souzai32
*    created: 04.08.2020 01:31:08
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long int n,m;
    cin >> n >> m;

    long long ans=1;
    if(n==m) ans*=2;
    else if(abs(n-m)>1) ans=0;

    for(int i=1; i<=n; i++){
        ans*=i;
        if(ans>=1000000007) ans%=1000000007;
    }
    for(int i=1; i<=m; i++){
        ans*=i;
        if(ans>=1000000007) ans%=1000000007;
    }

    cout << ans << endl;

    return 0;
}