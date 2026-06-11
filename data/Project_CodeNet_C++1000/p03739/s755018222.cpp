#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC059 C-Sequence
// 2020.06.03

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> A(N, 0);
  REPLL(i, N){
    cin >> A[i];
  }
  ll ansP = 0, ansM = 0;
  ll sumP = 0, sumM = 0;
  REPLL(i, N){
    ///////////////////////////////////////////////
    if(sumP <= 0){ // マイナス又は初期値のとき（次はプラスになる）
      if(A[i] >= 0){ //　A[i]がプラスのとき
        sumP += A[i];
        if(sumP <= 0){ // まだマイナスなら
          ansP += 1-sumP;
          sumP = 1;
        }
      }else{ // A[i]がマイナスのとき
        ansP += 1-A[i]; // 最低のプラスにしてやる
        sumP += 1;
        if(sumP <= 0){ // まだマイナスなら
          ansP += 1-sumP;
          sumP = 1;
        }
      }
    }else{ // プラスのとき（次はマイナスになる）
      if(A[i] <= 0){ //　A[i]がマイナスのとき
        sumP += A[i];
        if(sumP >= 0){ // まだプラスなら
          ansP += 1+sumP;
          sumP = -1;
        }
      }else{ // A[i]がプラスのとき
        ansP += 1+A[i]; // 最低のマイナスにしてやる
        sumP += -1;
        if(sumP >= 0){ // まだプラスなら
          ansP += 1+sumP;
          sumP = -1;
        }
      }     
    }
    ///////////////////////////////////////////////
    if(sumM < 0){ // マイナスのとき（次はプラスになる）
      if(A[i] >= 0){ //　A[i]がプラスのとき
        sumM += A[i];
        if(sumM <= 0){ // まだマイナスなら
          ansM += 1-sumM;
          sumM = 1;
        }
      }else{ // A[i]がマイナスのとき
        ansM += 1-A[i]; // 最低のプラスにしてやる
        sumM += 1;
        if(sumM <= 0){ // まだマイナスなら
          ansM += 1-sumM;
          sumM = 1;
        }
      }
    }else{ // プラス又は初期値のとき（次はマイナスになる）
      if(A[i] <= 0){ //　A[i]がマイナスのとき
        sumM += A[i];
        if(sumM >= 0){ // まだプラスなら
          ansM += 1+sumM;
          sumM = -1;
        }
      }else{ // A[i]がプラスのとき
        ansM += 1+A[i]; // 最低のマイナスにしてやる
        sumM += -1;
        if(sumM >= 0){ // まだプラスなら
          ansM += 1+sumM;
          sumM = -1;
        }
      }     
    }
  }
  ll ans = min(ansP, ansM);
  cout << ans << endl;
}
