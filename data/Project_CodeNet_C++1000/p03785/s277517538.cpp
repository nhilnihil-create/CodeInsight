#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N, C, K;
  cin >> N >> C >> K;
  int T[N];
  for(int i=0; i<N; i++)
    cin >> T[i];
  // 入力終わり

  // Tを昇順にソートしておく
  sort(T, T+N);

  int ans = 0;
  int tmp = 1;
  for(int i=0; i<N; i++){
    tmp = 1;
    //    cout << "i : " << i << endl;
    if(i == N-1){
      ans++;
      break;
    }
    int j = i+1;
    while(T[j]-T[i] <= K && tmp<C){
      if(T[i] <= T[j] <= T[i]+K){
	tmp++;
	j++;
	if(j>=N){
	  ans++;
	  goto end;
	}
      }
      else
	break;
    }
    ans++;
    i = j-1;
  }

 end:
  cout << ans << endl;
  
  return 0;
}
