#include<iostream>
int main(void){
  int N;
  std::cin >> N;
  int button[N];
  for (int i=0;i<N;i++){
    std::cin >> button[i];
  }

  int num = 1;
  int count = 0;
  for (int i=0;i<N+1;i++){
    num = button[num-1];
    count++;
    if (num == 2) break;
  }
  if (count == N+1){
    std::cout << -1;
  }else{
    std::cout << count;
  }
  
  return 0;
}