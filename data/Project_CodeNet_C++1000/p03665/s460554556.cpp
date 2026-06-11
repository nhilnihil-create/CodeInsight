#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
int mod =1000000007;
const double PI = acos(-1);
int main(){
    ll n,m,x;cin>>n>>m;bool f=false;
    rep(i,n){
        cin>>x;
        if(x%2)f=true;
    }
    ll ans =pow(2,n-1);
    if(!f&&m){
        ans=0;
    }
    else if(!f){
        ans=pow(2,n);
    }
    cout<<ans<<endl;
}