#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vll = vector<long long>;
#define PI 3.141592653
#define rep(i, n) for(ll i = 0; i < n; i++)

int main(){
  ll n, x;
  cin >> n >> x;

  vll v(n);
  vll w(n);
  rep(i, n) { cin >> v[i]; w[n-1-i] = v[i];}

  ll cnt1 = 0;
  rep(i, n-1){
    ll k = v[i] + v[i+1] - x;
    if(k > 0){
      if(v[i+1] > k){cnt1 += k; v[i+1] -= k; continue;}
      else{cnt1 += k; v[i] -= k - v[i+1]; v[i+1] = 0; continue;}
    }
  }

  ll cnt2 = 0;
  rep(i, n-1){
    ll k = w[i] + w[i+1] - x;
    if(k > 0){
      if(w[i+1] > k){cnt2 += k; w[i+1] -= k; continue;}
      else{cnt2 += k; w[i] -= k - w[i+1]; w[i+1] = 0; continue;}
    }
  }
  

  cout << min(cnt1, cnt2) << endl;
  

}