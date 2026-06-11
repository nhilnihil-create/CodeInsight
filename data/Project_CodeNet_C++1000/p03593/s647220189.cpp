#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++)cin>>a[i];
  map<char,int>m;
  for(auto it:a)for(auto it2:it)m[it2]++;
  vector<int>c(3,0);
  for(auto&it:m){
    c[2]+=it.second/4*4;
    it.second%=4;
    c[1]+=it.second/2*2;
    it.second%=2;
    c[0]+=it.second;
  }
  if(H%2==1&&W%2==1){
    if(c[2]>H*W-1-(H-1+W-1)){
      c[1]+=(c[2]-(H*W-1-(H-1+W-1)));
      c[2]=(H*W-1-(H-1+W-1));
    }
    if(c[0]==1&&c[1]==H-1+W-1&&c[2]==H*W-1-(H-1+W-1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else if(H%2==0&&W%2==1){
    if(c[2]>H*W-H){
      c[1]+=(c[2]-(H*W-H));
      c[2]=(H*W-H);
    }
    if(c[1]==H&&c[2]==H*W-H)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else if(H%2==1&&W%2==0){
    if(c[2]>H*W-W){
      c[1]+=(c[2]-(H*W-W));
      c[2]=(H*W-W);
    }
    if(c[1]==W&&c[2]==H*W-W)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else if(H%2==0&&W%2==0){
    if(c[2]==H*W)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
