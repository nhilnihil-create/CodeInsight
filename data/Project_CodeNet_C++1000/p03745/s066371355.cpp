#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int count = 1;
  bool a=false;
    for (int i = 0; i <N-1; ++i) {
      if(A.at(i)==A.at(i+1)){
        while (A.at(i)==A.at(i+1)){
          i++;
          if(i==N-1){
            a=true;
            break;
          }
        }
      }
      if (A.at(i)<A.at(i+1)) {
        while (A.at(i)<=A.at(i+1)){
          i++;
          if(i==N-1){
            a=true;
            break;
          }
        }
      }
      else if (A.at(i)>A.at(i+1)) {
        while (A.at(i)>=A.at(i+1)){
          i++;
          if(i==N-1){
            a=true;
            break;
          }
        }
      }
      if(a){
        break;
      }
      count++;
    }
  cout << count << endl;
}