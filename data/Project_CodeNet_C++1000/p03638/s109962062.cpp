#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll H,W;
  cin >> H >> W;
  ll N;
  cin >> N;
  vector<ll> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  int c[H][W];
  int i = 0, j = 0;
  int color = 0;
  for(int i = 0; i < H; i++){
    if(i % 2 == 0){
      for(int j = 0; j < W; j++){
	c[i][j] = color + 1;
	a[color]--;
	if(a[color] == 0){
	  color++;
	}
      }
    }else{
      for(int j = W-1; j >= 0; j--){
	c[i][j] = color + 1;
	a[color]--;
	if(a[color] == 0){
	  color++;
	}
      }
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}
