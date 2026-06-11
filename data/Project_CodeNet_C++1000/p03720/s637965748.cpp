#include<bits/stdc++.h>
using namespace std;
int main (void){
  int a,b,N,M;
  int road[55] = {};
  cin >> N >> M;
  
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;
    b--;
    road[a]++;
    road[b]++;
  }
  for(int i = 0; i < N; i++){
    cout << road[i] << '\n';
  }
  return 0;
}