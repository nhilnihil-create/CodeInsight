#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int next = 1;
  int count = 1;
  int check = 0;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  for (int i = 0; i < N; i++){
    if (vec.at(next - 1) == 2){
      check = 1;
      break;
    }else{
      count++;
      next = vec.at(next - 1);
    }
  }
  if (check == 1){
    cout << count << endl; 
  }else{
   cout << -1 << endl; 
  }
}