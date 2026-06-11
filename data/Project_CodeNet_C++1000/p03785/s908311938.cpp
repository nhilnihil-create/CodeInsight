#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;




int main (){
  ll n, c, k;
  cin >> n >> c >> k;

  ll cnt = 0;
  ll res = 1;
  ll time = 0;

  vector<ll> v(n, 0);
  for(ll i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.push_back(0LL);

  for(ll i = 1; i < n; i++){
    time += (v[i] - v[i-1]);
    if(time <= k){
      res++;
      if(res == c){cnt++; res = 0LL; time = v[i] - v[i+1];}
      }
    else{
      cnt++; res = 1LL; time = 0LL;
    }
    if(i == n-1 && res != 0){cnt++;}
  }
  if(c == 1){cnt = n;}
  cout << cnt << endl;
}