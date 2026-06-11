#include <iostream>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int c[N];

  for (int i = 0; i < N; i++){
    c[i] = 0;
  }
  

  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    c[a-1]++;
    c[b-1]++;
  }

  for (int i = 0; i < N; i++){
    printf("%d\n", c[i]);
  }
  
}
