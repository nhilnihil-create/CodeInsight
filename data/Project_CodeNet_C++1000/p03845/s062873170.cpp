#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,sum = 0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    sum += vec[i];
  }
  int M;
  cin >> M;
  for(int i=0; i<M; i++){
    int x = sum;
    int a,b;
    cin >> a >> b;
    x += b-vec[a-1];
    cout << x << endl;
  }
}