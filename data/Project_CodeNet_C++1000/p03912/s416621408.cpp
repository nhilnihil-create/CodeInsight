//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, M; cin >> N >> M;
  vector <int> X(N);
  for (int i = 0; i < N; i++){
    cin >> X[i];
  }
  sort(X.begin(), X.end());

  vector <int> cnt1(M), cnt2(M);
  for (int i = 0; i < N; i++){
    cnt1[X[i] % M]++;
  }

  int cnt = 1;
  for (int i = 0; i < N - 1; i++){
    if (X[i] == X[i + 1]){
      cnt++;
    }else{
      cnt2[X[i] % M] += cnt / 2;
      cnt = 1;
    }
  }
  cnt2[X[N - 1] % M] += cnt / 2;
  
  int ans = cnt1[0] / 2;
  cnt1[0] %= 2;
  
  for (int i = 1; i < M; i++){
    if (i != M - i){
      int m = min(cnt1[i], cnt1[M - i]);
      ans += m;
      cnt1[i] -= m;
      cnt1[M - i] -= m;
    }else{
      ans += cnt1[i] / 2;
      cnt1[i] = cnt1[i] % 2;
    }
  }


  for (int i = 1; i < M; i++){
    if (cnt1[i] >= 2 * cnt2[i]){
      ans += cnt2[i];
    }else{
      ans += cnt1[i] / 2;
    }
  }
  cout << ans << endl;
  

  return 0;
}
