#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

#define MOD 1000000007

int main(){
  ll N;
  cin >> N;
  vll prime(1000, 0);
  if(N==1){
    cout << 1 << endl;
    return 0;
  }
  for(int i = 2; i <= N; i++){
    ll NN = i;
    for(int j = 2; j*j <= NN; j++){
      if(NN % j == 0){
        ll counter = 0;
        while(NN % j == 0){
          NN /= j;
          counter++;
        }
        prime.at(j)+=counter;
      }
    }
    if(NN != 1){
      prime.at(NN)++;
    }
  }
  ll ans = 1;
  for(int i = 2; i < 1000; i++){
    ans *= prime.at(i) + 1;
    ans %= MOD;
  }
  cout << ans << endl;
}