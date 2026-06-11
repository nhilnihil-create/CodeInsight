#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1000000000+7;

int main(){
  int n;
  cin >> n;
  vector<string> s(2);
  for(int i=0;i<2;++i) cin >> s[i];

  vector<int> ss;
  for(int i=0;i<n;++i){
    if(s[0][i]==s[1][i]){
      ss.push_back(1);
    }else{
      ss.push_back(2);
      i++;
    }
  }
  int k=ss.size();
  ll ans;
  if(ss[0]==1) ans=3;
  else ans=6;
  //for(int i=0;i<k;++i) cout << ss[i] << endl;
  for(int i=1;i<k;++i){
    if(ss[i-1]==1 && ss[i]==1) ans=(ans*2)%MOD;
    else if(ss[i-1]==2 && ss[i]==1) ans=ans%MOD;
    else if(ss[i-1]==1 && ss[i]==2) ans=(ans*2)%MOD;
    else if(ss[i-1]==2 && ss[i]==2) ans=(ans*3)%MOD;
  }
  cout << ans << endl;
  return 0;
}
