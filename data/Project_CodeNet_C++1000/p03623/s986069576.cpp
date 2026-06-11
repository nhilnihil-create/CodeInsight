#include <bits/stdc++.h>
using namespace std;

int main() {
   int x , a , b ;
  cin >> x >> a >> b ;
  
  int A = abs(x-a) ;
  int B = abs(x-b) ;
  
  if(A>=B) cout << "B" << endl;
  else cout << "A" << endl;
}
