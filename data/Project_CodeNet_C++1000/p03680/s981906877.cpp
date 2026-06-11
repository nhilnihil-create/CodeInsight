#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N + 1);
  for (int i = 1; i < N + 1; i++){
    cin >> vec.at(i);
  }
  int index = 1, count = 0, tmp;
  while (index != 2){
    if (vec.at(index) == index){
      cout << -1;
      return 0;
    }
  tmp = vec.at(index);  
  vec.at(index) = index;
  index = tmp;
  count++;
  }
  cout << count;
  return 0;
}