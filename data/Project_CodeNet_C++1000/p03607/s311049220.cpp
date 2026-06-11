#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  map<int,int> count;
  for(int i=0; i<N; i++){
    cin >> A.at(i);
    count[A.at(i)]++;
  }
  int ans = 0;
  for(auto &d : count){
    if(d.second%2!=0){
      ans++;
    }
  }
  cout << ans;
  return 0;
}