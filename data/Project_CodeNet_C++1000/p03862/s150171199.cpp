#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N;
  long long x;
  cin >> N >> x;
  long long a[N];
  rep(i, N)
    cin >> a[i];
  //ここまで入力

  long long ans = 0;

  //1項目の値をx以下まで下げる
     if(a[0] > x){
      ans += (a[0]-x);
      a[0] = x;
     }
     
  long long sum;
  for(int i=1; i<N; i++){
    sum = a[i-1]+a[i];
    //二項間の和の超過分を計算していく
    //二項のうち，右側を書き換えていく
    if(sum > x){
      ans += (sum-x);
      a[i] -= (sum-x);
    }
  }

  cout << ans << endl;

  return 0;
}
