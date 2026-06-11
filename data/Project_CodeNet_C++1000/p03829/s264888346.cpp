#include<iostream>

using namespace std;
using ll = long long;

int n;
ll a, b;
ll x[100005];

ll ans = 0;

void input(){
  cin >> n >> a >> b;
  for(int i = 0; i < n; ++i){
    cin >> x[i];
    if(i > 0){
      ans += (x[i] - x[i - 1]) * a;
    }
  }
}

void solve(){
  for(int i = 1; i < n; ++i){
    if((x[i] - x[i - 1]) * a > b){
      ans -= (x[i] - x[i - 1]) * a;
      ans += b;
    }
  }
  cout << ans << endl;
}


int main(){
  input();
  solve();
}