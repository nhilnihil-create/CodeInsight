#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
  	cin >> vec.at(i);
  }
  
  int now = 0;
  for(int j=0; j < N; j++) {
    //cout << now;
    if(now == 1){
    	cout << j;
      	break;
    }
    else if (j == N-1){
    	cout << -1;
    }
    
    now = vec.at(now)-1;
  }
}