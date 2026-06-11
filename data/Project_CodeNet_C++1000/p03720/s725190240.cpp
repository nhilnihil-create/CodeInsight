#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> vec(M*2);
  for (int i=0; i<2*M; i++){
  	cin >> vec.at(i);
  }
  
  for (int j=0; j < N; j++) {
  	int n = 0;
    for(int k=0; k < 2*M; k++){
    	if (vec.at(k) == j+1){
        	n++;
        }
    }
    cout << n <<endl;
  }

  
}