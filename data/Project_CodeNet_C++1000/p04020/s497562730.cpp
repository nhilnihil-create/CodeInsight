#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll ans=0;
    rep(i,n){
        ll tmp=0;
        if(i==0){
            tmp+=a[i]/2;
            a[i]-=2*(a[i]/2);
        }
        else{
            bool f=false;
            if(a[i-1]>0){
                a[i]++;
                f=true;
            }
            tmp+=a[i]/2;
            a[i]-=2*(a[i]/2);
            if(tmp==0 && f) a[i]--;
        }
        ans+=tmp;
        //cout<<i<<" "<<tmp<<endl;
    }

    cout<<ans<<endl;
}