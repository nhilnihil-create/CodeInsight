#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int x, a, b;
  cin >> x >> a >> b;

  if (abs(x - a) <= abs(x - b)){
    cout << 'A' << endl;
  }else{
    cout << 'B' << endl;
  }
}
