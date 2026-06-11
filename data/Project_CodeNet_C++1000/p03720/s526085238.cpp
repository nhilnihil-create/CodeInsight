#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> B(M);
  for(int i=0;i<M;i++){
  	cin >> A.at(i) >> B.at(i);
  }
  vector<int> C(N);
  for(int j=0;j<N;j++){
    for(int k=0;k<M;k++){
    	if(A.at(k)==j+1 || B.at(k)==j+1) C.at(j)++;
    }
  }
  for(int l=0;l<N;l++){
  	cout << C.at(l) <<endl;
  }
}  