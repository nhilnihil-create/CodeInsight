#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define out(ans) cout << ans << endl;
const long long mod = 1e9 + 7;

int main(){
  string s;cin>>s;
  rep(i,s.size()){
    if(i==4)cout<<" ";
    cout<<s[i];
  }
  cout<<endl;

  return 0;
}
