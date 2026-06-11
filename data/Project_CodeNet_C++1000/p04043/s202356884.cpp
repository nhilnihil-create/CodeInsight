#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int five = 0, seven = 0;
  
  if (a == 5) five++;
  if (a == 7) seven++;
  
  if (b == 5) five++;
  if (b == 7) seven++;
  
  if (c == 5) five++;
  if (c == 7) seven++;
    
  if (five == 2 || seven == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}