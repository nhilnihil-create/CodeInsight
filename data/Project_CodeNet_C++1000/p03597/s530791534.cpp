#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  
  if(1 <= N && 100 >= N){
    if(0 <= A && N * N >= A){
      cout << N * N - A << endl;
    }else{
      cout << "Number is overfloating by chart. Please put nember under =>" << N * N << endl;
    }
  }else{
  cout << "Please put number 1 to 100." << endl;
  }
 }