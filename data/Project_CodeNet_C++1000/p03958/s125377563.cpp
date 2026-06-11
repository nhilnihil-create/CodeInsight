#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)
using Graph = vector<vector<int>>;
using pint = pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int k,t;cin>>k>>t;
    int a[t];
    int mx=0,sum=0;
    rep(i,t){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    sum-=mx;
    int ans=max(0,mx-1-sum);
    cout<<ans<<"\n";
}
