#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  int mincost=1e9;
  for(int i=-100;i<101;i++){
    int X=i;
    int cost=0;
    for(int j=0;j<N;j++){
      int B=X-A.at(j);
      cost+=B*B;
    }
    mincost=min(mincost,cost);
  }
  cout << mincost << endl;
}