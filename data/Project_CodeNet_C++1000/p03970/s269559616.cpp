#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  string S; cin >>S;
  string a="CODEFESTIVAL2016";
  int ans=0;
  rep(i,0,S.size()) {
    if (S[i]!=a[i]) {
      ans++;}
  }
  cout <<ans <<endl;
  return 0;
}
