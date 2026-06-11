#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> v(3*N);
  for(int i = 0; i < 3*N; i++){
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  int num = 0;
  int index = N;
  while(num < N){
    ans += v.at(index);
    num++;
    index += 2;
  }
  cout << ans << endl;
  // cerr << num << endl;
}
