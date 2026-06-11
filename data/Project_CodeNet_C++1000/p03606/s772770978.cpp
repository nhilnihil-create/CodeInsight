#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, li, ri, x = 0;

  cin >> N;

  for(int i = 0; i < N; i++){
      cin >> li >> ri;
      x = x + ri - li +1;
  }

  cout << x << endl;


}
