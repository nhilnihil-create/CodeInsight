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
  string ans="No";
  if (S.size()>=4 && S.substr(0,4)=="YAKI") {
    ans="Yes";
  }
  cout <<ans <<endl;
  return 0;
}
