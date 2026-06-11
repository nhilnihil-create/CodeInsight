#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N, M;
  cin >> N >> M;
  
  if (N + M >= 10)
    cout << "error" << endl;
  else
    cout << N + M << endl;
}