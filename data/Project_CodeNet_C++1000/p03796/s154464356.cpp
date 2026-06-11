#include <bits/stdc++.h>
using namespace std;


int main() {
  
  long long N;
  long long s=1;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    s *= i;
    s%=1000000007;

  }
 cout << s;
}
