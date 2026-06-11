#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,M; cin >> N >> M;
  ll ans = 0;

  if(M >= N * 2){
    ans += N;
    M -= N * 2;
    ans += M / 4;
  } else { 
    ans += M / 2;
  }
  cout << ans << endl;

}
