#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N, T;
  cin >> N >> T;
  vector<int> t(N);
  rep(i,N){
    cin >> t.at(i);
  }
  ll ans = T;
  for(int i=1; i<N; i++){
    int a = t.at(i)-t.at(i-1);
    if(a>=T){
      ans += T;
    }else{
      ans += a;
    }
  }
  cout << ans;
  return 0;
}