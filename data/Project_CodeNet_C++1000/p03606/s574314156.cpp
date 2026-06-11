#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  int ans=0;
  rep(i,n){
    int l,r;
    cin>>l>>r;
    ans+=r-l+1;
  }
  cout<<ans<<endl;
}