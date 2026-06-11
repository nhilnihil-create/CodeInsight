#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  long long ans=1e9;
  for(int x=-100;x<=100;x++){
    long long mini=0;
    rep(i,n){
      mini+=(a.at(i)-x)*(a.at(i)-x);
    }
    ans=min(ans,mini);
  }
  cout << ans;
}
      
      
  