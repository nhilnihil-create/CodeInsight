#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M;
  cin>>N>>M;
  
  vector<vector<int>> num(M,vector<int>(2));
  for(int i=0;i<M;i++){
    cin>>num[i][0]>>num[i][1];
  }
  
  vector<int> check(N);
  
  
  for(int i=0;i<M;i++){
    check[num[i][0]-1]++;
    check[num[i][1]-1]++;
  }
  
  
  for(int i=0;i<N;i++){
    cout<<check[i]<<endl;
  }
}