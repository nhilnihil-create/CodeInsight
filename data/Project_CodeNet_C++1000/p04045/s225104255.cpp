#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vi sieve(10);
  rep(i,k){
    int d; cin >> d;
    sieve[d] = -1;
  }
  vi num;
  rep(i,10) if(sieve[i] != -1) num.push_back(i);
  queue<int> q;
  for(int a : num) if(a != 0) q.push(a);
  while(1){
    int x = q.front(); q.pop();
    if(n <= x){
      cout << x;
      return 0;
    }
    for(int a : num) q.push(10*x+a);
  }
  cout << "\n";
  return 0;
}
