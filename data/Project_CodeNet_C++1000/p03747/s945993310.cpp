#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);i <= (e);(i)++)

#define int long long

int N;
i64 L,T;
vector<i64> X;
vector<i64> W;
vector<i64> Xs;

signed main(){
  cin >> N >> L >> T;
  X.resize(N);
  W.resize(N);
  rep(i,0,N - 1){
    cin >> X[i] >> W[i];
    if(W[i] == 1){
      Xs.push_back((X[i] + T) % L);
    }
    else{
      Xs.push_back((X[i] + L + (-T) % L ) % L);
    }
  }

  i64 zero = Xs.front();

  sort(begin(Xs),end(Xs));

  i64 cou = 0;

  rep(i,1,N - 1){
    if(W[0] != W[i]){
      i64 re = 0;
      if(W[0] == 1){
        re = X[i] - X[0];
      }
      else{
        re = (X[0] + L) - X[i];
      }
      if(re <= T * 2){
        i64 t = T * 2 - re;
        cou++;
        cou += t / (L);
      }
    }
  }


  if(W[0] == 2){
    cou = N + (- cou) % N;
  }

  vector<int> ans(N);
  int from = lower_bound(begin(Xs),end(Xs),zero) - begin(Xs);
  if(W[0] == 1 && Xs[from] == Xs[(from + 1) % N]){
    from++;
  }

  rep(i,0,N - 1){
    int index = (from + i) % N;
    ans[(i + cou) % N] = Xs[index];
  }
  for(int an : ans){
    cout << an << endl;
  }
}
