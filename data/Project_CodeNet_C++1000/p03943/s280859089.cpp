#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<ll,ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  vector<ll> A(3);
  cin >> A.at(0) >> A.at(1) >> A.at(2);
  sort(all(A));
  if(A.at(1)+A.at(0)==A.at(2)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
  