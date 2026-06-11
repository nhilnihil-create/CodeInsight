#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  int min_cost=100000000;
  for(int i=-100;i<101;i++){
    int cost=0;
    for(int j=0;j<N;j++){
      int B=A.at(j)-i;
      cost+=pow(B,2);
    }
    min_cost=min(min_cost,cost);
  }
  cout << min_cost << endl;
} 