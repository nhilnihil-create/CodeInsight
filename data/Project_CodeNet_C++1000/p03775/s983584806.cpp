#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  long long N;
  cin >> N;
  int m = INFINITY;
  for(long long i=1; i<=sqrt(N)+1; i++) {
    if(N%i==0) {
      int x = max(log10(i)+1,log10(N/i)+1);
      m = min(m,x); 
    }
    else continue;
  }
  cout << m << endl;
}