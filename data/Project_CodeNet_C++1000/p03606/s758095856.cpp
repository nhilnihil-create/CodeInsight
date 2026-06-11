#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<vector<int>> vec(N,vector<int> (2));
  for(int i=0;i<N;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  
  
  int sum=N;
  
  for(int i=0;i<N;i++){
    sum+=(vec[i][1]-vec[i][0]);
  }
  
  cout<<sum<<endl;
}