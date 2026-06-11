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
  int h,w;
  cin>>h>>w;
  vector<string> c(h);
  rep(i,h)cin>>c[i];
  vector<string> ans(2*h);
  rep(i,h){
    if(i==0){
      ans[0]=c[0];
      ans[1]=c[0];
      continue;
    }
    ans[2*i]=c[i];
    ans[2*i+1]=c[i];
  }
  rep(i,2*h){
    cout<<ans[i]<<endl;
  }
}