#include <iostream>
#include <map>

using namespace std;

int MOD = 1000000007;

int main(void){
  int N;
  cin >> N;
  //入力終わり

  //Nを素因数分解した結果を入れていく
  map<int, int> fact;

  //N！を考える
  for(int i=2; i<=N; i++){ //O(N)
    int n = i;
    //nを素因数分解し，素因数をfactに入れていく
    for(int j=2; j<=n; j++){ //nが素数の時が最悪でO(N)
      //jで割り切れれば，jを素因数に持つ
      if(n % j == 0){
	fact[j]++;
	//nを割っていけば計算量が減って嬉しい
	n /= j;
	//2から割り直すための処理
	//2(<- 例えば)で複数回割れる時に困るため
	j = 1;
      } //if
    } //j roop
  }

  //約数の個数の性質を使う
  long long ans = 1;
  for(auto m : fact)
    ans = (ans*(m.second+1) ) % MOD;
  
  cout << ans << endl;
  
  return 0;
}
