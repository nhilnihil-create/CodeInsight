#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long N,K;
  cin >> N >> K;
  unsigned long long answer=1;
  for(int i=0;i<N-1;i++){
    answer *= K-1; 
  }
  cout << K*answer << endl;
}
