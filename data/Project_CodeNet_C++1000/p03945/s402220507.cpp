#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  char now=s[0];
  int ans=0;
  for(int i=1; i<s.size(); i++){
    if(now!=s[i]){
      ans++;
      now=s[i];
    }
  }
  cout<<ans<<endl;
}

