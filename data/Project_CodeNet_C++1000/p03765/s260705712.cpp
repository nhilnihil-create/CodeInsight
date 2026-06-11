#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  string s,t;cin>>s>>t;
  vector<int> a(s.size()+1,0),b(t.size()+1,0);
  rep(i,s.size()){
    a[i+1]=a[i]+(s[i]=='A'?1:2);
  }
  rep(i,t.size()){
    b[i+1]=b[i]+(t[i]=='A'?1:2);
  }
  int n;cin>>n;
  rep(i,n){
    int w,x,y,z;cin>>w>>x>>y>>z;
    if((a[x]-a[w-1])%3==(b[z]-b[y-1])%3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}