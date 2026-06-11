#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int a,b,c,d;
  c = 0;
  d = 0;
  cin >> N;
    
   for (int i=0;i < N;i++){
     cin >> a >> b;
     c = b - a + 1;
     d += c;
    
     }
   cout << d << endl;
}
