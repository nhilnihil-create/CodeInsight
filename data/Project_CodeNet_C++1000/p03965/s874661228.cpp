#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
  string s;cin>>s;
  int g=0,p=0,ans=0;
  REP(i,s.size()){
    if(s.at(i)=='g') g++;
    else p++;
  }
  ans=(g-p)/2;

  cout<<ans;
}