#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s;
  cin >> s;
  ll ans=0;
  rep(i,s.size()-1){
    if(s.at(i)!=s.at(i+1)){
      ans++;
    }
  }
  cout << ans;

}