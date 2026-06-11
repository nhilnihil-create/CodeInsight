#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n; i++)

#define MAX 100000

using namespace std;

int main(void){
  int N;
  cin >> N;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //入力終わり

  //各数字が何回出てきたか
  int count[MAX+1];
  rep(i, MAX+1)
    count[i] = 0;

  //数字のカウント
  rep(i, N)
    count[ A[i] ]++;

  //2回以上出てくる数字を左と右から内側に向かって見ていく
  int l = 1, r = 100000;
  //0回または1回登場する数字を飛ばす
  while(count[l]<2){
    l++;
    //無限ループ回避
    if(l > MAX){
      //全部同じ数字なので1種類
      cout << N << endl;
      return 0;
    }
  }
  while(count[r]<2)
    r--;
  
  //登場回数が1になるまで左右から消していく
  while(l < r){
    
    while(count[l]<2)
      l++;
    while(count[r]<2)
      r--;

    //問題の操作を実行
    count[l]--; count[r]--;

    //登場回数が1か0なら1つ右にずらす
    if(count[l] < 2)
      l++;
    //登場回数が1か0なら1つ左にずらす
    if(count[r] < 2)
      r--;
  }

  //最後に残った場所は登場回数が2以上の可能性がある
  //同じ数字を選べば2つずつ消していけることを利用
  //偶数のときもこれで処理できる(厳密には違う)
  count[l] = count[l]%2;
  
  //登場回数の和をとっていく
  int ans = 0;
  rep(i, MAX+1)
    if(count[i] == 1)
      ans += 1;

  //解答
  cout << ans << endl;
  
  return 0;
}
