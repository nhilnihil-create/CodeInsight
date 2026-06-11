#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;

    int t[n],ans(0);
    rep(i,n){
        cin >> t[i];
        ans += t[i];
    }

    int m;  cin >> m;

    rep(i,m){
        int p,x;
        cin >> p >> x;
        ans -= t[p-1]-x;
        cout << ans << endl;

        ans += t[p-1]-x;
    }

    return 0;
}