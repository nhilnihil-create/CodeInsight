#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long x;
  cin >> x;
 
 //cout << x%11 << endl;
 
if (x%11>6)  {
 cout << (x-x%11)/11*2+2 << endl;
}
  
if ((x%11<7) && (x%11>0))  {
 cout << (x-x%11)/11*2+1 << endl;
} 
  
if (x%11==0)  {
 cout << (x-x%11)/11*2 << endl;
}  
  
}