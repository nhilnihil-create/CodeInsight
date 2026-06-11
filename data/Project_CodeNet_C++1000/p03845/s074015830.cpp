#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  int M;
  cin >> M;
  for (int i=1; i<=M; i++){
    int P, X;
    cin >> P >> X;
    vector<int> vec_c(N);
    vec_c=vec;
    vec_c.at(P-1) = X;
    int sum = 0;
    for (int j=0; j<N; j++){
      sum += vec_c.at(j);
    }
    cout << sum << endl;  
  }
}