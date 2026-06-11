#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> x(N);
  int cnt = 0;
  rep(i,N){
    cin >> x.at(i); 
    if(x.at(i) > K / 2){
      x.at(i) = K - x.at(i);
    }
    cnt += x.at(i);
  }
  cout << cnt*2 << endl;
}

