#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  string s;cin>>s;
  bool flag=false;
  int ans1,ans2;
  rep(i,s.size()-1){
    if(i<s.size()-2 && s[i]==s[i+2]){
      flag=true;
      ans1 = i;
      ans2 = i+2;
    }
    if(s[i]==s[i+1]){
      flag=true;
      ans1 = i;
      ans2 = i+1;
    }
  }
  if(flag) cout << ans1+1 << " " << ans2+1 << endl;
  else cout << -1 << " " << -1 << endl;
}