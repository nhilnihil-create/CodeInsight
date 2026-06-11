#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(M * 2);
  for (int i = 0; i < M * 2; i++) {
    cin >> vec.at(i) >> vec.at(i+1);
    i++;
  }
  
  vector<int> result(N);
  
  for (int i = 0; i < vec.size(); i++) {
    result.at(vec.at(i) - 1)++;
  }
  
  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i) << endl;
  }
}