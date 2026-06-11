#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int X[N];
  rep(i, N)
    cin >> X[i];
  //入力終わり

  long long ans = 0;

  //歩くときとテレポートするときのそれぞれのコスト
  long long costA, costB = B;
  rep(i, N-1){
    costA = (long long)(X[i+1]-X[i] )*A;
    //隣町に行くのにコストの小さい選択を順次していけばよい
    ans += min(costA, costB);
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
