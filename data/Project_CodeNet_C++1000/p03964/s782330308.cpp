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
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  ll N; cin >> N;
  vector<ll> T(N);
  vector<ll> A(N);
  rep(i,N) cin >> T[i] >> A[i];
  ll takahasi = 1;
  ll aoki = 1;
  rep(i,N){
    if(i==0){
      takahasi = T[i];
      aoki = A[i];
      continue;
    }
    ll lastT = takahasi;
    ll lastA = aoki;
    ll tt = max(takahasi/T[i], aoki/A[i]) * T[i];
    ll aa = max(takahasi/T[i], aoki/A[i]) * A[i];
    while(1){
      if(tt >= lastT && aa >= lastA){
        takahasi = tt;
        aoki = aa;
        break;
      }
      tt += T[i];
      aa += A[i];
    }
  }

  cout << takahasi + aoki << endl;
  return 0;
}
