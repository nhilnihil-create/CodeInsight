#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  // 正しい順番の時と、偶奇が一致していない奴を数えれば良い

  int N;
  cin >> N;
  vector<ll> v(N);
  map<ll,int> m;
  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    v.at(i) = tmp;
    m[tmp] = i;
  }

  sort(v.begin(), v.end());
  int ans = 0;
  for(int i = 0; i < N; i+=2){
    if(i%2 != m[v[i]]%2) ans++;
  }
  cout << ans << endl;


}
