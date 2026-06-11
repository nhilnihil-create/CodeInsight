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

int main(){
  ll N;
  cin >> N;
  map<ll, ll> m;
  vector<Pll> X(0);
  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    if(!m.count(A)){
      m[A] = X.size();
      X.push_back(Pll(A, 1));
    }
    else{
      X.at(m.at(A)).second++;
    }
  }
  sort(ALL(X), greater<Pll>());
  ll x = 0;
  for(int i = 0; i < X.size(); i++){
    if(X.at(i).second <= 1) continue;
    
    if(x == 0){
      if(X.at(i).second <= 3){
        x = X.at(i).first;
      }
      else{
        cout << X.at(i).first * X.at(i).first << endl;
        return 0;
      }
    }
    else{
      cout << x * X.at(i).first << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}