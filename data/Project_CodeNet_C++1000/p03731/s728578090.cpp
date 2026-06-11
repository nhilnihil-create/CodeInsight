#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N,T;
  cin >> N >> T;
  vector<int> t(N);
  for(int i = 0; i < N; i++){
    cin >> t[i];
  }
  ll ans = 0;
  for(int i = 1; i < N; i++){
    int gap = t[i] - t[i-1];
    if(gap >= T){
      ans += T;
    }else{
      ans += gap;
    }
  }
  ans += T;
  cout << ans << endl;
}
