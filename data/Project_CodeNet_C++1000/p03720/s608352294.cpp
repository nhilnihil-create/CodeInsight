#include <bits/stdc++.h>
using namespace std;

int main() {
int N, M;
  
    
    cin >> N>>M;
  int D = 2*M;
    vector<int> A(D), Sum(N);
    for(int i=0; i < D; i++){
        cin >>A.at(i);
    }
    for(int i=0; i < D ;i++){
      for(int j =0; j <N; j++){
        if(A.at(i) == j+1){
          Sum.at(j) ++ ;
      }
      }
    }
    for(int i=0; i < N ;i++)
    cout << Sum.at(i)<<endl;
}
