#include <bits/stdc++.h>
using namespace std;

int main() {				
  char op;					// *constarint*
  int A,B,ans;			    // 1 <= A,B <= 10＾9
  					        // op i s'+' or '-'
  cin >> A >> op >> B;
 if(op == '+'){
   ans = A + B;
 }else if(op == '-'){
   ans = A - B;
 }
  
 cout << ans << endl;
  
}
