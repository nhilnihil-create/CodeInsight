#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int A,B;
  char op;
  cin >> A >> op >> B;

  if (op == '+') cout << A + B << endl;
  else cout << A - B << endl;
}
