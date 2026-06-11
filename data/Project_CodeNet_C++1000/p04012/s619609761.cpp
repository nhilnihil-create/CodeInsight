#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const long long INF=1e9+5;
const string alp="abcdefghijklmnopqrstuvwxyz";
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;

int main() {
  string s;
  cin>>s;
  vector<ll> judge(26,0);
  for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      if(s[i]==alp[j]){
        judge[j]++;
      }
    }
  }
  bool ans=true;
  for(int i=0;i<26;i++){
    if(judge[i]%2!=0){
      ans=false;
      break;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
