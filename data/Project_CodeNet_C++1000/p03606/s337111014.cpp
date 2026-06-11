#include <bits/stdc++.h>
using namespace std;
#define req(i, s, n) for( int i=(int)s; i<(int)n; i++ )

int main() {
  int N;
  cin >> N;
  
  int sum = 0;
  
  req(i, 0, N){
    int l, r;
    cin >> l >> r;
    
    sum += (r - l + 1);
  }
  
  cout << sum << endl;
}