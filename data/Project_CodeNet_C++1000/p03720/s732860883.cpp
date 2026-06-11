#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  N++;
  
  vector<int> n(N);
  vector<int> m(M);

  int a, b;
  
  for(int i=0; i<M; i++){
    cin >> a >> b;
    
    n.at(a) += 1;
    n.at(b) += 1;
  }
  
  for(int i=1; i<N; i++){
    cout << n.at(i) << endl;
  }
}
