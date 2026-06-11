#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, n) for(ll i = 0; i < n; i++)

int main(){
  ll n; cin >> n;
  vector<tuple<ll, ll , ll, ll>> v(n);
  rep(i, n){
    cin >> get<0>(v[i]);
    get<1>(v[i]) = i+1;
    }
  
  sort(v.begin(), v.end());
  
  rep(i, n){
    get<2>(v[i]) = i+1;
    get<3>(v[i]) = 0;
  }

  sort(v.begin(), v.end());

  rep(i, n){
    if(i == 0){
      get<3>(v[0]) = (n-get<2>(v[i])+1)*(get<0>(v[i]));
    }
    else{
      get<3>(v[i]) = (n-get<2>(v[i])+1)*(get<0>(v[i])-get<0>(v[i-1]));
    }
  }

  ll memo = get<1>(v[n-1]);
  ll res = n-1;

  for(ll i = n-1; i >= 0; i--){
    if(memo < get<1>(v[i])){
      get<3>(v[res]) += get<3>(v[i]); get<3>(v[i]) = 0; continue;
    }
    if(memo > get<1>(v[i])){
      memo = get<1>(v[i]); res = i; continue;
    }
  }




  rep(i, n){
    swap(get<1>(v[i]), get<0>(v[i]));
  }

  sort(v.begin(), v.end());

  rep(i, n){
    cout << get<3>(v[i]) << endl;
  }

}       