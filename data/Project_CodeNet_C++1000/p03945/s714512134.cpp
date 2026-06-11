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
  rep(i,0,n-1){
    if(s[i]!=s[i+1]){
      ans++;
    }
  }
  cout<<ans<<endl;
}