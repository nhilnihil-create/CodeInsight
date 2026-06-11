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
  int N; cin >> N;
  vector <ll> A(3 * N);
  for (int i = 0; i < 3 * N; i++) cin >> A[i];
  
  priority_queue <ll, vector<ll>, greater<ll> > que1;
  priority_queue <ll> que2;

  vector <ll> sum1(N + 1), sum2(N + 1);

  ll sum = 0;
  for (int i = 0; i < N; i++){
    sum += A[i]; que1.push(A[i]);
  }
  sum1[0] = sum;
  for (int i = 0; i < N; i++){
    sum += A[N + i];
    que1.push(A[N + i]);
    sum -= que1.top();
    sum1[i + 1] = sum;
    que1.pop();
  }
  
  sum = 0;
  for (int i = 0; i < N; i++){
    sum += A[i + 2 * N]; que2.push(A[i + 2 * N]);
  }
  
  sum2[N] = sum;
  for (int i = N - 1; i >= 0; i--){
    sum += A[N + i]; que2.push(A[N + i]);
    sum -= que2.top(); sum2[i] = sum;
    que2.pop();
  }
  
  ll ans = -1e18;
  for (int i = 0; i < N + 1; i++){
    ans = max(ans, sum1[i] - sum2[i]);
  }
  cout << ans << endl;

  return 0;
}
