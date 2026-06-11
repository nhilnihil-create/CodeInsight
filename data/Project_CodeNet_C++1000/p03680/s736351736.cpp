#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec.at(i);
  int count = 0;
  int ans = 0;
  int answer = 0;
  for(int i = 0; i < N; i++){
    ans++;
    if(vec.at(count) == 2){
      answer = ans;
      break;
    }
    count = vec.at(count) - 1;
  }
  cout << (answer == 0 ? -1 : answer) << endl;
}
