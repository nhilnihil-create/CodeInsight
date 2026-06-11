#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{

  string A, B, C;
  cin >> A >> B >> C;

  char flag='a';
  int A_idx=0;
  int B_idx=0;
  int C_idx=0;

  while(1){
    if(flag == 'a'){
      if(A_idx==A.length()){
        cout << "A" << endl;
        return 0;
      }
      flag = A[A_idx];
      A_idx++;
    }
    if(flag == 'b'){
      if(B_idx==B.length()){
        cout << "B" << endl;
        return 0;
      }
      flag = B[B_idx];
      B_idx++;
    }
    if(flag == 'c'){
      if(C_idx==C.length()){
        cout << "C" << endl;
        return 0;
      }
      flag = C[C_idx];
      C_idx++;
    }
  }

}
