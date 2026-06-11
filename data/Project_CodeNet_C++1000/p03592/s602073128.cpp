#include<iostream>
using namespace std;

int main(){
  int N,M,K; cin >> N >> M >> K;
  bool flag = false;
  for(int m = 0; m <= M; m++){
    for(int n = 0; n <= N; n++){
      if(K == m * N + n * M - 2 * m * n){
        flag = true;
      }
    }
  }

  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
