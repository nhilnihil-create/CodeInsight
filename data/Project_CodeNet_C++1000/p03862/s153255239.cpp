#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  ll N, x;cin >> N >> x;
  vector <ll> a(N);
  rep(i, N) cin >> a[i];
  ll ans= 0;
  rep(i, N-1){
    int num = a[i] + a[i+1];
    if (num <= x) continue;
    if (num-x <= a[i+1])a[i + 1] -= num-x;
    else a[i+1] = 0;
    ans += num-x;
  }
  cout << ans << endl;
}