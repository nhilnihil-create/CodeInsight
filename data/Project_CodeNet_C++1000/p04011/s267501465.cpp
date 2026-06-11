#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    int ans=0;
    rep(i,n){
        if(i+1>k) ans+= y;
        else ans+= x;
    }
    cout << ans << endl;
}