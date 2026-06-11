#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> a_i(M), b_i(M), ways(N);
  
  for (int i=0;i<M;i++){
    cin >> a_i.at(i) >> b_i.at(i);
    
    for (int j=0;j<N;j++){
      if ( a_i.at(i)==j+1 || b_i.at(i)==j+1 )
        ways.at(j)++;
    }
  }
  for (int i=0;i<N;i++)
    cout << ways.at(i) << endl;
}