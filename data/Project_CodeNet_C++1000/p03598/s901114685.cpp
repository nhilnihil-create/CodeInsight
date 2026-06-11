#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  for(int i=0; i<N; i++){
    cin >> x.at(i);
  }
  int ans = 0;
  for(int i=0; i<N; i++){
    ans += min(x.at(i), K-x.at(i));
  }
  cout << 2*ans;
  return 0;
}