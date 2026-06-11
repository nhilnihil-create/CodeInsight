#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(3*N);
  for(int i=0; i<3*N; i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  long long ans = 0;
  for(int i=N; i<3*N; i+=2){
    ans += a.at(i);
  }
  cout << ans;
  return 0;
}