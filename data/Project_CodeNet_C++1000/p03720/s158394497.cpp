#include<bits/stdc++.h>
using namespace  std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> vec1(M);
  vector<int> vec2(N);
  
  for(int j=0; j<M; j++){
	for(int i=0; i<2; i++){
	   	cin >> vec1.at(i);   
        if(vec1.at(i)%N == 0)vec2.at(N-1)++;
      	else vec2.at((vec1.at(i)%N)-1)++;
  	}
   }
  
  for(int i=0; i<N;i++){
    cout << vec2.at(i) << endl;
  }
  
  
  
}