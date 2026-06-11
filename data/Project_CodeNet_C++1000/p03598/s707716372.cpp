#include<iostream>

using namespace std;

int main(){
  int N, K, ans=0;
  cin >> N >> K;
  int x[N];
  for (int i = 0; i < N; i++){
    cin >> x[i];
  }

  for (int i = 0; i < N; i++){
    if(x[i] < (K - x[i])){
      ans += x[i] * 2;
    }else{
      ans += (K - x[i]) * 2;
    }
  }
  printf("%d\n", ans);
}
