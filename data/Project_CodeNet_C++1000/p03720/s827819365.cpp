#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M;
  cin >> N >> M;
  vector<int> k(N);
  int a,b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    k.at(a-1)++;
    k.at(b-1)++;
  }
  for(int p = 0; p < N; p++){
    cout << k.at(p) << endl;
  }
}