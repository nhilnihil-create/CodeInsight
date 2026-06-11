#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, n;
  cin >> n;
  vector<int> c(n), d(n);
  a = b = 0;
  for(int i = 0; i < n; i++){
    cin >> c[i] >> d[i];
  }
  for(int i = 0; i < n; i++){
    if((a + c[n - i - 1]) % d[n - i - 1] == 0)
      continue;
    else{
      b = d[n - i - 1] - (a + c[n - i - 1]) % d[n - i - 1];
      a += b;
    }
  }
  cout << a << endl;
}