#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,l,r,t=0;
  cin >> N;
  while(N--){
    cin >> l >> r;
    t += (r-l)+1;
  }
  cout << t << endl;
}
