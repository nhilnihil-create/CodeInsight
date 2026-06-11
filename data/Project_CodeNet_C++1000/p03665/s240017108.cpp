#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, P;
  cin >> N >> P;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //入力終了

  //偶数と奇数の数
  int eve_n = 0, odd_n = 0;
  rep(i, N)
    if(A[i]&1)
      odd_n++;
    else
      eve_n++;

  //偶数しかないとき
  if(odd_n==0){
    //P=0なら，全ての袋を選ぶか選ばないかで，2^N通り
    if(P == 0){
      long long ans = 1;
      for(int i=0; i<N; i++)
	ans *= 2;
      cout << ans << endl;
    }
    //P=1は無理
    else
      cout << 0 << endl;
    return 0;
  }
  
  //2^(N-1)が答え
  long long ans = 1;
  rep(i, N-1)
    ans *= 2;
  cout << ans << endl;
  
  return 0;
}
