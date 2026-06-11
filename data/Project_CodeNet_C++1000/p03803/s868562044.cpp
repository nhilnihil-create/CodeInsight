#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  if (a == b){
    cout << "Draw" << endl;
  }else if (a == 1){
    cout << "Alice" << endl;
  }else if (b == 1){
    cout << "Bob" << endl;
  }else if (a > b){
    cout << "Alice" << endl;
  }else{
    cout << "Bob" << endl;
  }
}
