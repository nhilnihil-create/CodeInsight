#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<pair<int, int> > AB(N, pair<int, int>());
  REP(i, N){
    int a, b; cin >> a >> b;
    AB[i] = {a, b};
  }
  sort(AB.begin(), AB.end(), greater<pair<int, int> >());
  cout << AB[0].first + AB[0].second << endl;
}