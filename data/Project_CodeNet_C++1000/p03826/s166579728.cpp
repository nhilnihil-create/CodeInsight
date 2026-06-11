#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  ll A,B,C,D;
  cin >> A >> B >> C >> D;

  if(A*B >= C*D){
    cout << A*B;
  }
  else{
    cout << C*D;
  }

return 0;
}