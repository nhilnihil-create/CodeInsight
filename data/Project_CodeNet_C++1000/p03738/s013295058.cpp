#include <iostream>
#include <string>

using namespace std;

int main(){
  string A, B;
  cin >> A >> B;

  if (A.size() > B.size()){
    printf("GREATER\n");
  }else if (A.size() < B.size()){
    printf("LESS\n");
  }else{
    int flg = 0;
    for (int i = 0; i < A.size(); i++){
      if(A[i] > B[i]){
        flg = 1;
        break;
      }else if(A[i] < B[i]){
        flg = 2;
        break;
      }
    }
    if (flg == 1){
      printf("GREATER\n");
    }else if(flg == 2){
      printf("LESS\n");
    }else{
      printf("EQUAL\n");
    }
  }
}
