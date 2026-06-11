#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int X, A, B;
  cin >> X >> A >> B;

  if (abs(A - X) < abs(B - X)){
    cout << "A" << endl;
  }
  else
  {
    cout << "B" <<endl;
  }
  
}