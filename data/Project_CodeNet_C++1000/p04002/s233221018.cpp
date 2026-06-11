#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main(){
  ll H, W;
  int N;
  map<ll, int> mpa;
  ll num[10];
  fill(num, num + 10, 0);
  cin >> H >> W >> N;
  for(int i = 0; i < N; i++){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    for(ll j = 0; j < 3; j++){
      for(ll k = 0; k < 3; k++){
	ll na = a + j;
	ll nb = b + k;
	if(na < 2 || nb < 2 || na >= H || nb >= W) continue;
	mpa[na * W + nb]++;
      }
    }
  }
  num[0] = (H - 2) * (W - 2);
  for(auto e : mpa){
    num[e.second]++;
    num[0]--;
  }
  for(int i = 0; i <= 9; i++){
    cout << num[i] << endl;
  }
  return 0;
}
