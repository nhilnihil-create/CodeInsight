#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int n,m;cin>>n>>m;
  string s[100],t[100];
  rep(i,n)cin>>s[i];
  rep(i,m)cin>>t[i];
  bool flag=false;
  rep(i,n-m+1){
    rep(j,n-m+1){
      bool po=true;
      rep(k,m){
        rep(l,m){
          if(s[i+k][j+l]!=t[k][l]){
            po=false;k=m,l=m;
          }
        }
      }
      if(po){
        flag=true;
        i=n,j=n;
      }
    }
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}