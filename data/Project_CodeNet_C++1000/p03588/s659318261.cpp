#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,max_A=-1,max_B=-1;
  cin >> N;
  for(int i=0;i<N;i++){
    int A,B;
    cin >> A >> B;
    if(A>max_A){
      max_A=A;
      max_B=B;
    }
  }
  cout << max_A+max_B << endl;
}