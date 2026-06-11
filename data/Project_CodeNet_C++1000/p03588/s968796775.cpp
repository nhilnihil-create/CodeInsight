#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int , int>> p(N);
  
  for(int i = 0; i < N ; i++){
    int a;
    int b;
    cin >> a >> b;
    p.at(i) = make_pair(a, b);
  }
  
  sort(p.begin(), p.end());
    
  cout << p.at(N-1).first + p.at(N-1).second << endl;
}