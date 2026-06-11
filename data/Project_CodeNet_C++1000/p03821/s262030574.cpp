#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);

  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  for(int i = 0; i < N; i++){
    ll tmp1,tmp2;
    cin >> A.at(i) >> B.at(i);
  }

  ll ans = 0;
  for(int i = N-1; i >= 0; i--){
    ll tmp1 = A.at(i);
    ll tmp2 = B.at(i);
    ll mod = (tmp1+ans) % tmp2;
    ans += (mod == 0 ? 0 : tmp2 - mod);
  }
  cout << ans << endl;
}
