#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,sum;
  cin >> N;

  sum = 0;
  
  for (int i=0; i<N; i++){
  	int l,r,x;
    cin >> l >> r;
    x =  r-(l-1);
    sum += x;
  }
  
  cout << sum << endl;
  
}
