#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n;
  cin >> n;
  //cout << n << endl;
  string s;
  cin >> s;
  // rep(i,n) {
  //   cout << s.at(i) << endl;
  // }

  ll count_leftclose = 0, count_rightclose = 0;

  rep(i,n) {
    if(s.at(i) == '(') count_leftclose++;
    else {
      if(count_leftclose == 0) {
        count_rightclose++;
      }
      else {
        count_leftclose--;
      }
    }
  }

  rep(i,count_rightclose) {
    cout << '(';
  }
  rep(i,n) {
    cout << s.at(i);
  }
  rep(i,count_leftclose) {
    cout << ')';
  }
  cout << endl;
}
