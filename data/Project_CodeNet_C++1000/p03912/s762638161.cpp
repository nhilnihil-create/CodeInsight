// 方針
// xが書かれたカードの枚数をA[x]とする。
// xをmodMで分類する。x modM = kなるA[x]の和をS[k]とする。(0 <= k < M)
// modMでkとM-kが書かれたカードはペアにできるので，この方法でmin(S[k], S[M-k])個のペアがまず作れる。(0<= k <= M/2)
// ※k=0, M/2 の場合は別に考える。なお，この方法が最適かどうかは棚上げする。
// 仮にS[k]>=S[M-k]とする。合計S[k]-S[M-k]枚のx(x=k modM)のカードのうち，xが書かれたものの枚数をB[x]とする。
// B[x]が奇数であれば，xが書かれたカードは最後に1枚余る。
// そこで，B[x]のうち奇数であるようなxの個数(q[k])が最小になるように，M-k modMが書かれたカードとペアにする。
// A[x]のうち奇数であるものの個数をp[k]とすると，q[k]を以下のようにでき，かつ，これがq[k]のmin。
// (1) p[k] >= S[M-k] のとき，q[k] = p[k] - S[M-k]
// (2) p[k] < S[M-k] かつ S[M-k] - p[k] = 0 のとき，q[k] = 0
// (3) p[k] < S[M-k] かつ S[M-k] - [[k] = 1 のとき，q[k] = 1
// 上記方法により各k(1 <= k < M/2)に対し，q[k](S[k]<S[M-k]であればq[M-k])の最小値の合計に，
// k=0の場合に相当するB[0] mod2 及びB[M/2] mod2(Mが偶数のとき)を加え，
// Nから引いて2で割れば答えが得られる。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  // cout << "N, M:"; //
  // cout << N << " " << M << endl; //
  vector<int> X(N);
  // cout << "X:"; //
  rep(i, N) cin >> X.at(i);
  // for (int Xi : X) cout << Xi << " "; //
  // cout << endl; //

  map<int, int> A;
  for (int Xi : X) {
    if (!A.count(Xi)) A[Xi] = 1;
    else A[Xi] += 1;
  }
  // cout << "A:";
  // for (pair<int, int>pA : A) cout << "(" << pA.first << ", " << pA.second << ") ";
  // cout << endl; //

  vector<int> S(M); // 0~M-1
  for (pair<int, int>pA : A) {
    S.at(pA.first % M) += pA.second;
  }
  // cout << "S:";
  /* for (int Si : S) cout << Si << " ";
  cout << endl; // */

  vector<int> p(M);
  for (pair<int, int>pA : A) {
    if (pA.second % 2 == 1) p.at(pA.first % M)++;
  }
  // cout << "p:";
  // for (int pi : p) cout << pi << " ";
  // cout << endl;
  
  int r = 0; // 残るカードの総数
  r += p.at(0) % 2;
  rep2(k, 1, (M + 1) / 2) {
    // cout << "k:" << k << endl;
    if (S.at(k) >= S.at(M - k)) {
      if (p.at(k) >= S.at(M - k)) r += p.at(k) - S.at(M - k);
      else if ((S.at(M - k) - p.at(k)) % 2 == 1)  r++;
    } else {
      if (p.at(M - k) >= S.at(k)) r += p.at(M - k) - S.at(k);
      else if ((S.at(k) - p.at(M - k)) % 2 == 1) r++;
    }
    // cout << "r:" << r << endl;
  }
  if (M % 2 == 0) {
    r += p.at(M / 2) % 2;
  }

  int ans = (N - r) / 2;
  cout << ans << endl;
}