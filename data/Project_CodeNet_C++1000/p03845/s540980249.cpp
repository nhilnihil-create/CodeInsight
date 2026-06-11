#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  int T[N];
  rep(i, N)
    cin >> T[i];
  int M;
  cin >> M;
  int P[M], X[M];
  rep(i, M)
    cin >> P[i] >> X[i];
  //入力終了

  //ドリンクP, Xをなめる
  rep(i, M){
    int ans = 0;
    //時間Tをなめる
    rep(j, N){
      //問題番号と，ドリンクが適用される問題番号が一致
      if(j == P[i]-1)
	ans += X[i];
      else
	ans += T[j];
    }
    //解答
    cout << ans << endl;
  }

  return 0;
}
