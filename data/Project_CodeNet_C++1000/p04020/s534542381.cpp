#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    ll a[n];
    ll ans=0;
    ll cnt=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]==0){
            ans+=cnt/2;
            cnt=0;
        }
        else cnt+=a[i];
    }
    ans+=cnt/2;
    cout<<ans<<endl;
}


