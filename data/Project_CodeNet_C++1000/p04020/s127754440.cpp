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
const int mod =1000000007;
const double PI = acos(-1);
int main(){
    int n;cin>>n;
    vector<ll>a(n,0);
    ll ans =0;
    rep(i,n){
        ll b;cin>>a[i];
        //ans+=b/2;
        //if(b%2)a[i]=true;
    }
    rep(i,n){
        ans+=a[i]/2;
        if(a[i]%2&&i!=n-1&&a[i+1]!=0){
            a[i+1]--;
            ans++;
        }
    }
    cout<<ans<<endl;
}