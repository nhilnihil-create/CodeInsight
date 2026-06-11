#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int n;cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    
    sort(a,a+n,greater<ll>());
    
    int cc=0;
    ll b[2];
    
    rep(i,n){
        if(a[i]==a[i+1] && cc==0){
            b[0]=a[i];
            a[i+1]=0;
            cc=1;
        }
        if(a[i]==a[i+1] && cc==1){
            b[1]=a[i];
            cout<<b[0]*b[1]<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
	return 0;
}