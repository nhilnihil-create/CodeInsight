#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,X=0;
  cin >> N >> K;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  for(int i=0; i<K; i++){
    X += vec[i];
  }
  cout << X << endl;
}
