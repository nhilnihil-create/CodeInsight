#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, M;
  cin >> N >> M;

  vector <int> a(2 * M);
  //vector <int> b(M);
  rep(i,2 * M) cin >> a.at(i);

  vector <int> num(N);//都市iから伸びている道路の数
  rep(i,N){
    rep(j,2 * M){
      if (a.at(j) == i + 1) num.at(i) += 1;
    }
  }

  rep(i,N) cout << num.at(i) << endl;
}
