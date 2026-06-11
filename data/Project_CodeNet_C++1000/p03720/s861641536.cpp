#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;

  int a, b;

  //各都市番号が何回出てきたかを数えることに帰着
  int ans[N];
  rep(i, N)
    ans[i] = 0;

  //出現回数を数える
  rep(i, M){
    cin >> a >> b;
    ans[a-1]++;
    ans[b-1]++;
  }

  //解答
  rep(i, N)
    cout << ans[i] << endl;
  
  return 0;
}
