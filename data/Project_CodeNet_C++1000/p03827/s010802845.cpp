#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  string s;
  cin>>s;
  int ans=0;
  int x=0;
  rep(i,s.length()){
    if(s[i]=='I') x++;
    if(s[i]=='D') x--;
    ans=max(ans,x);
  }
  cout<<ans<<endl;
}