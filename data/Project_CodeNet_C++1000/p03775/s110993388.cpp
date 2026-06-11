# include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
//既存のデータ型の名前をtypedefでllに書き換える
//64ビット以上が保証される
using namespace std;
#include <cmath>
int cnt_digits(ll n){//llは型
  int digits = 0;
  while (n>0){
    n /= 10;
    ++digits;
  }
  return digits;


}

int main(){
  ll N;
  cin >> N;

  int ans = cnt_digits(N);
  //まず桁数maxである元々のNを答えに置いておく
  for(ll a=1LL;a*a<=N;++a){//LLは整数リテラル、aがlong long型なのでLL型の１
    if(N%a !=0) continue;
    //continueは繰り返し文の処理を飛ばし、ブロックの先頭の位置に戻ってちぎの処理を続ける
    ll b = N/a;
    int c = max(cnt_digits(a),cnt_digits(b));
    //桁数の最小はNの桁数と(aとb)の桁数の最大を比較して小さい方を更新していけばいいので
    ans = min(ans,c);


  }
  cout << ans << endl;

  return 0;
}
