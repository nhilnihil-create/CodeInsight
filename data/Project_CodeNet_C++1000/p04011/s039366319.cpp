#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  int N,K,X,Y;
  cin >> N >> K >> X >> Y;
  int sum=0;
  if(N < K){sum = N*X;}
  else{sum = K*X + (N-K)*Y;}
  cout << sum << endl;
}