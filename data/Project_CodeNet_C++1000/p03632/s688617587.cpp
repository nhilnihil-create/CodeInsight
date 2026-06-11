#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  if(B <= C || D <= A) cout << 0 << endl;
  else if(A <=  C && C <= B && B <= D) cout << B - C << endl;
  else if(A <= C && D <= B) cout << D - C << endl;
  else if(C <= A && B <= D) cout << B - A << endl;
  else if(C <= A && A <= D && D <= B) cout << D - A << endl;
  
}
