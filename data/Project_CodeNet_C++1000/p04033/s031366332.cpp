#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B;
  cin >> A >> B;
  if(A<=0 && B>=0) cout << "Zero" << endl;
  else if(A>0 && B>0) cout << "Positive" << endl;
  else{
    if((B-A)%2==0) cout << "Negative" << endl;
    else cout << "Positive" << endl;
  } 
}