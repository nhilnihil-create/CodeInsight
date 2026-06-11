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
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    vector<ll> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+a[i];
    vector<bool> ok(n,false);
    ok[n-1]=true;
    int ans=1;
    for(int i=n-2;i>=0;i--){
        if(!ok[i+1]) continue;
        if(s[i+1]*2>=a[i+1]){
            ans++;
            ok[i]=true;
        }
    }

    cout<<ans<<endl;
}
