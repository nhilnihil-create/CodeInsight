#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  string s,a="CODEFESTIVAL2016";cin>>s;
  int ans=0;
  REP(i,16){if(s[i]^a[i])++ans;}
  cout<<ans<<"\n";
}