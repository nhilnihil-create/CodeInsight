#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  int N=S.size();
  for(int i=(N-1)/2*2;i>=0;i-=2)
    if(S.substr(0,i/2)==S.substr(i/2,i/2)){
      cout<<i<<endl;
      return 0;
    }
}