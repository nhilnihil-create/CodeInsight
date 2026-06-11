#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> r(N);
  
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    r.at(a - 1)++;
    r.at(b - 1)++;
  }
  
  for(int i = 0; i < r.size(); i++)
    cout << r.at(i) << endl;
}