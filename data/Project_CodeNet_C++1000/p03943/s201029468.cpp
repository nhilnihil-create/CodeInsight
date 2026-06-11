#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  int ab = A+B;
  int bc = B+C;
  int ca = C+A;

  if(ab == C)
    cout << "Yes" << endl;
  else
    if(bc == A)
      cout << "Yes" << endl;
    else
      if(ca == B)
	cout << "Yes" << endl;
      else
	cout << "No" << endl;
  
  return 0;
}
