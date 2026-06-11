#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long int N, K;
  
  cin >> N >> K;
  
  vector<long long int> cnt(1e5 + 1);
  for(int i = 0;i < N;i++){
    int a, b;
    cin >> a >> b;
    cnt.at(a) += b;
  }
  
  for(int i = 1;;i++){
    if(K <= cnt.at(i)){
      cout << i << endl;
      return 0;
    }
    K -= cnt.at(i);
  }
  
  return 0;
}