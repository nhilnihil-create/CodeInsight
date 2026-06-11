#include <bits/stdc++.h>
using namespace std;

int main() {
  
  //データの数
  int N, A=1, i;
  cin >> N;
  
  vector<int> data ( N,0 );
  
  for(i = 0; i < N ; i++){
  	cin >> data.at(i) ;
  }
  
  for(i = 0; i < N ; i++){
  	A=data.at(A-1);
    if(A == 2){
      break;
    }
  }
  
  if(i == N){
  	cout << -1 << endl;
  }
  else{
  	cout << i+1 << endl;
  }
  
}
