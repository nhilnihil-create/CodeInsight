#include <iostream>

using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  //入力終了

  //全員同じ数を持っている
  if(A == B && B == C){
    //偶数なら無限ループ
    if((A&1)==0)
      cout << -1 << endl;
    //奇数なら操作を行えない
    else
      cout << 0 << endl;
    return 0;
  }
    
  int ans = 0;
  //A, B，Cが全て偶数であれば続行
  while( (A&1)==0 && (B&1)==0 && (C&1)==0 ){
    int a = A;
    int b = B;
    int c = C;
    A = (b+c)/2;
    B = (c+a)/2;
    C = (a+b)/2;
    ans++;
  }

  //解答
  cout << ans << endl;
    
  return 0;
}
