#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  vector<int>vec(N);
  for(int i=0; i<M; i++){
    int A,B;
    cin >> A >> B;
    vec[A-1]++;
    vec[B-1]++;
  }
  for(int i=0; i<N; i++){
    cout << vec[i] << endl;
  }
}