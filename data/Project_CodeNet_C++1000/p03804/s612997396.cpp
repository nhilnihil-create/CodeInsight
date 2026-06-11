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
  int n,m;
  cin >> n >> m;

  vector< vector<char> > a(n,vector<char>(n));
  vector< vector<char> > b(m,vector<char>(m));

  rep(i,n) {
    rep(j,n) {
      cin >> a.at(i).at(j);
    }
  }

  rep(i,m) {
    rep(j,m) {
      cin >> b.at(i).at(j);
    }
  }

  char b_leftup = b.at(0).at(0);

  rep(i,n - m + 1) {
    rep(j,n - m + 1) {

      if(a.at(i).at(j) == b_leftup) {
        bool flag = true;
        
        for(int row = i; row < i + m; row++) {
          for(int column = j; column < j + m; column++) {

            if(a.at(row).at(column) != b.at(row - i).at(column - j)) {
              flag = false;
            }
            
          }
          if(!flag) break;
          if(row == i + m - 1) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
}
