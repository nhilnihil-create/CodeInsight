#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  long long A[N], B[N];
  rep(i, N)
    cin >> A[i] >> B[i];
  // 入力終了

  long long ans = 0;
	         
  for(int i=N-1; i>=0; i--){
    // i+1個目のボタンを押した結果をi個目の整数に反映させる
    A[i] = A[i] + ans;

    // i番目にボタンを最低何回押さないといけないか
    long long tmp;
    // 既に条件を満たしている
    if(A[i]%B[i] == 0)
      tmp = 0;
    // B[i]の倍数までに必要な回数
    else
      tmp = B[i]-(A[i]%B[i]);

    // 累積和的に更新
    ans = ans + tmp;
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
