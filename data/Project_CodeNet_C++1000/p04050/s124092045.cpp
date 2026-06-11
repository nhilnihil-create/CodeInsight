#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  int N, M;
  cin >> N >> M;
  
  int oddcount = 0;
  int odd[2];
  int A[M];
  int i;
  int r;
  for(i=0; i<M; ++i){
    cin >> r;
    if(r%2 != 0){
      if(oddcount > 1){
        cout << "Impossible" << endl;
        return 0;
      }else{
        odd[oddcount] = r;
        ++oddcount;
      }
    }else{
      A[i-oddcount] = r;
    }
  }
  if(oddcount == 0){
    for(i=0; i<M; ++i){
      cout << A[i] << " ";
    }
    cout << endl;
    if(A[0] == 2){
      cout << M+1 << endl;
      cout << "1 ";
      for(i=1; i<M; ++i){
        cout << A[i] << " ";
      }
      cout << "1" << endl;
    }else{
      cout << M+2 << endl;
      cout << A[0]-2 << " 1 ";
      for(i=1; i<M; ++i){
        cout << A[i] << " ";
      }
      cout << "1" << endl;
    }
  }else if(oddcount == 1){
    for(i=0; i<M-1; ++i){
      cout << A[i] << " ";
    }
    cout << odd[0] << endl;
    if(odd[0] == 1){
      cout << M << endl;
      cout << "1 ";
      for(i=0; i<M-1; ++i){
        cout << A[i] << " ";
      }
      cout << endl;
    }else{
      cout << M+1 << endl;
      cout << "1 ";
      for(i=0; i<M-1; ++i){
        cout << A[i] << " ";
      }
      cout << odd[0]-1 << endl;
    }
  }else if(oddcount == 2){
    cout << odd[0] << " ";
    for(i=0; i<M-2; ++i){
      cout << A[i] << " ";
    }
    cout << odd[1] << endl;
    if(odd[1] == 1){
      cout << M-1 << endl;
      cout << odd[0]+1 << " ";
      for(i=0; i<M-2; ++i){
        cout << A[i] << " ";
      }
      cout << endl;
    }else{
      cout << M << endl;
      cout << odd[0]+1 << " ";
      for(i=0; i<M-2; ++i){
        cout << A[i] << " ";
      }
      cout << odd[1]-1 << endl;
    }
  }
  return 0;
}