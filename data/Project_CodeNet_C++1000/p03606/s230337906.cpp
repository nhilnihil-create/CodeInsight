#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,total=0;
  cin >> N;

  while(N){
    int l,r;
    cin >> l >> r;
    
    total += r-l+1;
    
    N--;
  }
  cout << total << endl;
}
