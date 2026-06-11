#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> v(100000+1,0);

  ll ans = 0;  
  for(int i = 0; i < N; i++){
    ll tmp1,tmp2;
    cin >> tmp1 >> tmp2;

    ans += tmp2 - tmp1 + 1;
  }
  cout << ans<< endl;

}
