#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N,K;
  int total = 0;
  cin >> N >> K;
  rep(i, N) {
    int x;
    cin >> x;
    if((K - x) >= x){
      total += x * 2;
    }else{
      total += (K - x) * 2;
    }
  }
  cout << total;
}