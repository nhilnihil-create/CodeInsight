#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin >> N >> L;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  bool a=false;
  int C;
  for(int i=0;i<N-1;i++){
    if(A.at(i)+A.at(i+1)>=L){
      C=i+1;
      a=true;
      break;
    }
  }
  if(!a){
    cout << "Impossible" << endl;
  }
  else{
    cout << "Possible" << endl;
    for(int i=1;i<C;i++){
      cout << i << endl;
    }
    for(int i=N-1;i>C;i--){
      cout << i << endl;
    }
    cout << C << endl;
  }
}