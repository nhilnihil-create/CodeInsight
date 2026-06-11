#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  string s;
  cin>>s;
  rep(i,s.size()) if(i%2==0) cout<<s[i];
  cout<<endl;
}
