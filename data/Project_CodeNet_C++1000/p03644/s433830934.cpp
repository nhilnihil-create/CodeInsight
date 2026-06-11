#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, count = 0, max_count = -1, max_N = -1;
  cin >> N;
  for(int i=1; i<N+1; i++){
    count = 0;
    int j = i;
    while(j%2 == 0){
      j = j/2;
      count++;
    }
    if(count > max_count){
      max_count = count;
      max_N = i;
    }
  }
  
  cout << max_N << endl;
}