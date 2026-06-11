#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//arc070_c
//i-1秒からi秒にかけて、i移動できるカンガルー
//0秒から1秒の間は1移動できる。1秒から2秒の間は2移動できる
//なにも考えずにすべて、足す
//ある数 s を足したときを出力する
//ちょうどXに止まらなくて良いか → sを足したときのあまりtは、s以下といえる
//s以下はすでに足してあるので、tを足さなかったことにすればよい
int main(){
  ll X,res;
  cin >> X;

  ll sum = 0;

  for(ll i = 1; i <= X; i++)
  {
    sum += i;
    if(sum >= X)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}