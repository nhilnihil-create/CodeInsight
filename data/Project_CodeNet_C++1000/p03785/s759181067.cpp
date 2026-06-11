#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N, C, K, T[100001], b_cnt=1, p_cnt=1, tmp=0;
  cin >> N >> C >> K;
  for(int i=0; i<N; i++){
    cin >> T[i];
  }

  sort(T, T+N);
  tmp = T[0];
  for(int i=1; i<N; i++){
    if(tmp+K < T[i] || p_cnt >= C){
      b_cnt++;
      p_cnt=1;
      tmp=T[i];
    }else p_cnt++;
  }

  cout << b_cnt << endl;
  return 0;
}