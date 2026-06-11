#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  string s;
  cin>>s;
  int n=s.size();
  ////////////
  ll ans=0;
  char c=s[0];
  rep(i,n-1){
    if(s[i+1]!=c){
      ans++;
      c=s[i+1];
    }
  }
  cout<<ans<<endl;
}