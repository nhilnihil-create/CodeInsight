#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}


bool ok(int N,vector<int>& D){
  while(N){
    rep(i,sz(D)){
      if(N%10==D[i]) return false;
    }
    N/=10;
  }
  return true;
}

void solve(){
  int N, K; cin >> N >> K;
  vector<int> D(K); rep(i,K) cin >> D[i];
  while(1){
    if(ok(N,D)) {
      cout << N << endl;
      break;
    }
    else N++;
  }
}

int main(){
  solve();
  return 0;
}
