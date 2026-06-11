#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;
using ll=long long;

int main() {
  string S; cin >>S;
  ll ans=0;
  ll all=1<<(S.size()-1);
  rep(bit,0,all) {
    string temp="";
    rep(i,0,S.size()) {
      temp+=S[i];
      if (bit>>i&1) {
        ans+=stoll(temp);
        temp="";
      }
    }
    ans+=stoll(temp);
  }
  cout <<ans <<endl;
}
