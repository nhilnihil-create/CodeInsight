#include <iostream>
#define rep(i, n) for(int i=0; i<N; i++)

using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  int x[N];
  rep(i, N)
    cin >> x[i];
  //入力終わり

  int ans = 0;
  rep(i, N){
    //距離が小さい方を選べばよい
    ans += min(x[i], K-x[i])*2;
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
