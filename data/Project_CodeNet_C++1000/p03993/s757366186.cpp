#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int ans=0;
  rep(i,n){
    int v=a.at(i);
    if(a.at(v-1)==i+1){
      ans++;
    }
  }
  cout << ans/2;
}
