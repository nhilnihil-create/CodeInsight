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
ll lcm(ll x, ll y) { return x / __gcd(x, y) * y; }
int main(){
   int n;cin>>n;
   ll a[n];
   rep(i,n)cin>>a[i];
   ll l =a[0];
   rep(i,n){
       l= lcm(l,a[i]);
   }
   cout<<l<<endl;
}
