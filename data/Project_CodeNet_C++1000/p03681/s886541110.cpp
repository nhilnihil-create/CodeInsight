#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll c=1000000007;
    ll n,m; cin >> n >> m;
    ll ans=1;
    if(n==m){
        rep2(i,n+1){
            ans*=i;
            ans%=c;
        }
        ans=ans*ans;
        ans%=c;
        ans*=2;
        ans%=c;
        cout << ans << endl;
    }
    else if(n==m+1 || n==m-1){
        n=min(n,m);
        rep2(i,n+1){
            ans*=i;
            ans%=c;
        }
        ans=ans*ans;
        ans%=c;
        ans*=(n+1);
        ans%=c;
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
}