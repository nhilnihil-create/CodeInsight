#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll ans=0;
        ans=2*(n/11);
        if(n%11==0)ans+=0;
        else if(n%11<=6)ans++;
        else ans+=2;
        cout<<ans<<endl;
}
