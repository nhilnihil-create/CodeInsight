#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,c;
  cin >> n;
  c = 0;
  int a,b;
  
  for (int i = 0 ; i < n ; i++){
    cin >> a >> b;
    c = c-a+b+1;
  }
  cout << c << endl;
}
