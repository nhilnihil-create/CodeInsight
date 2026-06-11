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
#include <deque>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const long long INF = 1e18;
const double PI = 2 * asin(1);

int main(){
  int N; ll K; cin >> N >> K;
  
  vector < pair<ll, ll> > AB(N);
  for (int i = 0; i < N; i++){
    ll A, B; cin >> A >> B;
    AB[i] = make_pair(A, B);
  }
  sort(AB.begin(), AB.end(), greater<pair<ll,ll> >());

  vector <ll> candi;
  candi.push_back(K);

  ll cnt = 0;
  while (pow(2, cnt) <= K){
    cnt++;
  }

  vector <bool> k(cnt);
  for (int i = 0; i < cnt; i++){
    if (K % 2 == 1) k[i] = true;
    K /= 2;
  }
  
  ll now = 0;
  for (int i = cnt - 1; i >= 0; i--){
    if (k[i] == true){
      ll C = now;
      for (int j = i - 1; j >= 0; j--){
        C += pow(2, j);
      }
      candi.push_back(C);
      now += pow(2, i);
    }
  }

  ll ans = 0;
  for (int i = 0; i < candi.size(); i++){
    ll now = 0, A = 0;
    for (int j = 0; j < N; j++){
      ll n = now | AB[j].first;
      if (n <= candi[i]){
        now = n;
        A += AB[j].second;
      }
    }
    ans = max(A, ans);
  }
  cout << ans << endl;
  
  return 0;
}
