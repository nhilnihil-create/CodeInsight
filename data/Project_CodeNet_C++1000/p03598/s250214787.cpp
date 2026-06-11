#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector <int> x(N);
  int sum = 0;
  
  for (int i=0;i<N;i++) {
     cin >> x.at(i); 
     int d = min(x.at(i),max(K-x.at(i),x.at(i)-K));
     sum += 2*d;
  }
  cout << sum << endl;
  }
