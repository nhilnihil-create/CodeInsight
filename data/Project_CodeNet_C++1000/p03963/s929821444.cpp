#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  long long K;
  long long ans=1;
  cin >> N;
  cin >> K;
  ans = K;
  for(int i=0; i < N-1; i++) ans *= K-1;
  cout << ans << endl;
}
