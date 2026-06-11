#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  int N,M;
  cin >> N >> M;
  vector<pair<int,int>> A(N),B(M);
  rep(i,N){
    int a,b;
    cin >> a >> b;
    A.at(i) = make_pair(a,b);
  }
  rep(i,M){
    int c,d;
    cin >> c >> d;
    B.at(i) = make_pair(c,d);
  }
  vector<int> ans(N);

    rep(i,N){
      int min_length = 1e9;
      rep(j,M){
        int length = abs(A.at(i).first - B.at(j).first) 
          + abs(A.at(i).second - B.at(j).second);
        if(length < min_length){
          min_length = length;
          ans.at(i) = j + 1;
        }
      }
    }
  rep(i,N){
    cout << ans.at(i) << endl;
  }

return 0;
}
