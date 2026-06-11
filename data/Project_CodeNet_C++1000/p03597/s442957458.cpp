#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, W;
  cin >> N >> W;
  while(N < 1 || N > 100 || W < 0 || W > N*N){
    cin >> N >> W;
  }
  cout << N*N - W <<endl;
}