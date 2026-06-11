#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int H,W,h,w;cin>>H>>W>>h>>w;
  int r=(H/h);
  int c=(W/w);
  int rem=(H%h)*W+(W%w)*H-(H%h)*(W%w);//H*W-r*c*h*w;
  if(H%h+W%w<=0){
      cout<<"No"<<"\n";
      return 0;
  }
  cout<<"Yes"<<"\n";
  rep1(i,H){
      rep1(j,W){
          int buf=r*c+5;
          if(i%h==0&&j%w==0){
              buf*=-h*w+1;
            buf-=1;
          }
          cout<<buf<<" ";
      }
      cout<<endl;
  }
  return 0;
}
