#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0, M = 0;
  cin >> N >> M;
  if(N > 0){
    cout << "Positive";
  }
  else if(N == 0 || M == 0){
    cout << "Zero";
  }
  else if(N < 0 && M > 0){
    cout << "Zero";
  }
  else{
    if((M-N)%2 == 0){
      cout << "Negative";
    }
    else{
      cout << "Positive";
    }
  }
}