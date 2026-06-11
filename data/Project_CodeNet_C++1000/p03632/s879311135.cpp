#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> A(101);
  for(int i = a; i <= b; i++){
    A[i]++;
  }
  for(int i = c; i <= d; i++){
    A[i]++;
  }
  int ans = 0;
  for(int i = 0; i <= 100; i++){
    if(A[i] == 2) ans++;
  }
  if(ans == 0) cout << 0 << endl;
  else cout << ans - 1 << endl;
}
