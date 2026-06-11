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
  string s,t;cin>>s>>t;
  int n=s.length()+t.length();
  rep(i,n){
    if(i%2==0)cout<<s[i/2];
    else cout<<t[i/2];
  }
  cout<<endl;
  return 0;
}