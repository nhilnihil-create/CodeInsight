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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int n;
string s;
string res;
bool solve(bool f,bool sec){
  //true->sheep, false->wolf
  bool last=false;
  bool nxt=sec;
  bool bef=f;
  bool cur=sec;
  bool hoge;
  string ans;
  if(f&&sec){
    if(s[0]=='o')last=true;
  }
  else if(f&&(!sec)){
    if(s[0]=='x')last=true;
  }
  else if((!f)&&sec){
    if(s[0]=='x')last=true;
  }
  else{
    if(s[0]=='o')last=true;
  }
  if(f){
    ans+='S';
  }
  else{
    ans+='W';
  }
  rep1(i,n-1){
    if(cur){
      ans+='S';
    }
    else{
      ans+='W';
    }
    if(s[i]=='o'&&cur){
      nxt=bef;
      bef=cur;
      cur=nxt;
    }
    else if(s[i]=='x'&&!cur){
      nxt=bef;
      bef=cur;
      cur=nxt;
    }
    else if(s[i]=='x'&&cur){
      nxt=!bef;
      bef=cur;
      cur=nxt;
    }
    else if(s[i]=='o'&&!cur){
      nxt=!bef;
      bef=cur;
      cur=nxt;
    }
  }
  if(f==nxt){
    if(last&&ans[n-1]=='S'){
      res=ans;
      return true;
    }
    else if(!last&&ans[n-1]=='W'){
      res=ans;
      return true;
    }
  }
  return false;
}
signed main(){
  cin>>n;
  cin>>s;
  bool flag=false;
  flag=flag||solve(true,true);
  //if(flag)goto FINE;
  flag=flag||solve(false,true);
  //if(flag)goto FINE;
  flag=flag||solve(true,false);
  //if(flag)goto FINE;
  flag=flag||solve(false,false);
  //FINE:
	if(flag){
    cout<<res<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
  return 0;
}
