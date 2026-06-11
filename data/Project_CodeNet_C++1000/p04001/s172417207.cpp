#include<iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); ++i)

using namespace std;

int main(){
  string S;
  ll N, K, l, sum, tmp, ans=0;
  cin >> S;
  vector<int> X(N), Y(N), C(N, -1);

  N = S.size();

  rep(i, (1<<(N-1))){
    sum = 0;
    tmp = 0;
    rep(j, N){
      tmp += S[j] - '0';
      if(i&1<<j && j != N-1) {
        tmp *= 10;
      }else{
        sum += tmp;
        tmp = 0;
      }
    }
    ans += sum;
  }

  cout << ans << endl;

  return 0;
}
