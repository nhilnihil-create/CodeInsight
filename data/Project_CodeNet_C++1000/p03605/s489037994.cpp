#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int n;
  cin >> n;

  int x = n % 10;
  int y = n / 10;
  if (x == 9 || y == 9){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
