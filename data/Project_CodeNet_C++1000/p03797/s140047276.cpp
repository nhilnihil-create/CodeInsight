#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  long long n,m;
  cin>>n>>m;
  if(n>=m/2) cout<<m/2<<endl;
  else cout<<n+(m-2*n)/4<<endl;
  return 0;
}
