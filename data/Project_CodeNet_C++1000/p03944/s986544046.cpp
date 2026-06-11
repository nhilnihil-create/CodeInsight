#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;



int main() {
ll N, W, H;cin >> W >> H >> N;
ll left = 0, right = W, ceil = H, floor = 0;

rep(i, 0, N){

  ll a, b, c;cin >> a >> b >> c;

  if(c == 1)left = max(left, a);

  if(c == 2)right = min(right, a);

  if(c == 3)floor = max(floor, b);

  if(c == 4)ceil = min(ceil, b);

}
  
  //cout << left << " " << right << " " << ceil << " " << floor << endl;

if(right - left < 0 || ceil - floor < 0)cout << 0;

else cout << (right - left)*(ceil - floor);

}