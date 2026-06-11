#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  string o,e;
  cin>>o>>e;
  string ans;
  if(o.length()-e.length()==0){
    rep(i,o.length()){
      ans+=o[i];
      ans+=e[i];
    }
  }
  if(o.length()-e.length()==1){
    rep(i,o.length()-1){
      ans+=o[i];
      ans+=e[i];
    }
    ans+=o[o.length()-1];
  }
  cout<<ans<<endl;
}