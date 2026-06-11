#include <iostream>
using namespace std;

int main (){
  int total = 0;
  int N, M;
  cin >> N;
  int arrT[N];
  for (int i = 0; i < N; i ++){
    cin >> arrT[i];
  }
  cin >> M;
  int arrP[M], arrX[M];
  for (int i = 0; i < M; i ++){
    total = 0;
    cin >> arrP[i] >> arrX[i];
    for (int j = 0; j < N; j ++){
      if (j + 1 == arrP[i]){
        total += arrX[i];
      } else {
        total += arrT[j];
      }
    }
    cout << total << '\n';
  }
}