#include <bits/stdc++.h>
using namespace std;

int main() {
  long i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  if((i>0&&j>0)&&(l>0&&i%2+j%2+l%2>=2)) {
    cout << o+3+(i-1)/2*2+(j-1)/2*2+(l-1)/2*2 << endl;
  } else {
    cout << o+i/2*2+j/2*2+l/2*2 << endl;
  }
}