#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c;
  cin >> a >> b >>c;

  if (a + b == c || b + c == a || c + a == b){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
