#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  long long res;
  cin >> N >> K;
  res = K;
  for(int i=2;i<=N;i++)
    res *= (K-1);
  cout << res << endl;
  
  return 0;
  
}