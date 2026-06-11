#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

int main(){
  ll N,T; cin >> N >> T;
  vector<ll>t(N);
  for(ll i=0;i<N;i++) cin >> t.at(i);

  ll X = 0;

  for(ll i=0;i<N-1;i++){
    X += min(t.at(i+1)-t.at(i),T);
  }

  cout << X + T << endl;

  return 0;
}