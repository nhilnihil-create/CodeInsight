#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> sumV(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int a, b, c;
  cin >> a >> b >> c;

  if(a + b == c || b + c == a || c + a == b){
    cout << "Yes" <<endl;
  } else{
    cout << "No" <<endl;
  }
}
