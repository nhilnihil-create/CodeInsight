#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  int i=1;
  while(2*i<n){
    bool p=true;
    rep(j,0,i){
      if(s[j]!=s[i+j]) p=false;
    }
    if(p) ans=i;
    i++;
  }
  cout<<2*ans<<endl;
}