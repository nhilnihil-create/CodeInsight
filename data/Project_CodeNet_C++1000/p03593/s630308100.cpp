#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
int main(){
  int h,w;cin>>h>>w;
  vector<int> num(26,0);
  vector<string> a(h);
  bool judge=true;
  rep(i,h)cin>>a[i];
  rep(i,h){
    rep(j,w){
      int buf=a[i][j]-'a';
      num[buf]++;
    }
  }
  if(h%2==0&&w%2==0){
    rep(i,26){
      if(num[i]%4!=0)judge=false;
    }
  }
  else if(h%2!=0&&w%2!=0){
    int margin1=1;
    int margin2=h+w-2;
    margin2/=2;
    rep(i,26){
      if(num[i]%4!=0){
        if(num[i]%2==0){
          if(margin2>0)margin2--;
          else judge=false;
        }
        else{
          if(margin1>0)margin1--;
          else judge=false;
        }
      }
    }
  }
  else{
    rep(i,26){
      if(num[i]%2!=0)judge=false;
      num[i]/=2;
    }
    if(h%2!=0){
      int margin=w/2;
      rep(i,26){
        if(num[i]%2!=0){
          if(margin>0)margin--;
          else judge=false;
        }
      }
    }
    if(w%2!=0){
      int margin=h/2;
      rep(i,26){
        if(num[i]%2!=0){
          if(margin>0)margin--;
          else judge=false;
        }
      }
    }
  }
  if(judge)cout<<"Yes";
  else cout<<"No";
  cout<<endl;
  return 0;
}
