#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, numberA, numberB;
  cin >> N >> M;
  
  vector<int> count(N);
  for(int i=0; i<N; i++){
    count.at(i)=0; 
  }
  
  for(int j=0; j<M; j++){
    cin >> numberA >> numberB;
    count.at(numberA-1)++;
    count.at(numberB-1)++;
  }
  
  for(int i=0; i<N; i++){
    cout << count.at(i) << endl;
  }
}