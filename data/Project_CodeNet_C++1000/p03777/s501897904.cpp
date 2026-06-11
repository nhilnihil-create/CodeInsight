#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  char a, b;
  cin >> a >> b;

  if (a == 'H' && b == 'H'){
    cout << 'H' << endl;
  }else if (a == 'H' && b == 'D'){
    cout << 'D' << endl;
  }else if (a == 'D' && b == 'H'){
    cout << 'D' << endl;
  }else if (a == 'D' && b == 'D'){
    cout << 'H' << endl;
  }
}
