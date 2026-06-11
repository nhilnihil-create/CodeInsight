#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N, M, K; cin >> N >> M >> K;

  for(ll i = 0; i <= N; i++){
    for(ll j = 0; j <= M; j++){
      ll tmp = 0;
      tmp += i * (M-j);
      tmp += j * (N-i);
      if(K==tmp){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
