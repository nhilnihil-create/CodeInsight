#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  map<int, int> data;
  for (int i = 0; i < N; i++) data[A.at(i)]++;
  int count = 0;
  for (auto p : data){
    int v = p.second;
    if (v % 2 == 1) count++;
  }
  
  cout << count << endl;
}
