#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll N,A,B; cin>>N>>A>>B;
    vector<ll>a(N);
    rep(i,N)cin>>a[i];
    ll ans =0;
    rep(i,N-1){
        if((a[i+1]-a[i])*A<B){
            ans+=(a[i+1]-a[i])*A;
        }
        else ans+=B;
    }
    cout<<ans<<endl;
}


