#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<int64_t> a(4);
  int64_t N;
  
  for(int i=0; i < 4; i++){
    cin >> a.at(i);
  }
  cin >> N;
  
  int64_t min2=1000000000;
  for(int i=0; i < 4; i++){
    if( std::pow(2,3-i) * a.at(i) <= min2){
      min2 = std::pow(2,3-i) * a.at(i);
    }
  }
  
  int64_t min1=1000000000;
  for(int i=0; i < 3; i++){
    if( std::pow(2,2-i) * a.at(i) <= min1){
      min1 = std::pow(2,2-i) * a.at(i);
    }
  }
  
  if (2 * min1 <= min2){
    cout << N * min1 << endl;
  }
  
  else{
    cout << (N / 2) * min2 + (N%2) * min1 << endl;
  }
  
	return 0;
}
