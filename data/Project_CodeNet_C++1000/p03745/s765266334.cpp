#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N+1];
  rep(i, N)
    cin >> A[i];
  //入力終了

  //実装上つけた
  A[N] = A[N-1]+(A[N-1]-A[N-2]);

  int ans = 0;
  for(int i=0; i<N; i++){
    //cout << i+1 << "-" ;

    //同じならカウントしなくていい
    //(次に単調増加/減少するところまで飛ばす)
    if(A[i] == A[i+1])
      continue;

    //単調増加するとき
    else if(A[i] < A[i+1]){
      while(A[i]<A[i+1] || A[i]==A[i+1])
	i++;
      ans++;
    }

    //単調減少するとき
    else if(A[i] > A[i+1]){
      while(A[i]>A[i+1] || A[i]==A[i+1])
	i++;
      ans++;
    }
    
    //cout << i+1 <<endl;
  }

  //解答
  cout << ans << endl;
    
  return 0;
}
