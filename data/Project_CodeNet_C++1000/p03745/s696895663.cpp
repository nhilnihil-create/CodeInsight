#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

ll a[200000];

int main(void){
    ll n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    int i=0;
    while(1){
        int j,k;
        for(j=i;j<n-1;j++){
            if(a[j]>a[j+1]) break;
        }
        for(k=i;k<n-1;k++){
            if(a[k]<a[k+1]) break; 
        }
        i=max(j+1,k+1);
        ans++;
        if(i==n) break;
    }
    cout<<ans<<endl;
}