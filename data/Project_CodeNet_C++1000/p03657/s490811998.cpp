#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
}
