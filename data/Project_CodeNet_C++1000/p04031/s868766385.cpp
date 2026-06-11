#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,min_cost=1000000000;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=-100;i<101;i++){
    int cost=0;
    for(int j=0;j<N;j++){
      cost+=(i-A.at(j))*(i-A.at(j));
    }
    min_cost=min(min_cost,cost);
  }
  cout << min_cost << endl;
} 