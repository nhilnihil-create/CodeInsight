#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

//#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  ll N, T, ans = 0;
  cin >> N >> T;
  ll a[N];
  rep(i, N){
    cin >> a[i];
  }

  ll tmp = a[0] + T;
  ans += T;
  for(int i = 1; i < N; i++){
    ans += T;
    if(tmp > a[i]){ // 時間が被っているとき
      ans -= tmp - a[i]; // 被った分をひく
    } 
    tmp = a[i] + T;
  }
  
  cout << ans << endl;

}
