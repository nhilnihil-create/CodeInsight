#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,X,Y;
  cin >> N >> K >> X >> Y;
  int res = X * min(N,K);
  res += Y * max(N-K,0);
  cout << res << endl;
  
  return 0;
  
}