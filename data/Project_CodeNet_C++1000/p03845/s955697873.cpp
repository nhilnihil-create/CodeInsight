#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> T(N);
  for(int i=0;i<N;i++){
    cin>>T[i];
  }
  
  int M;
  cin>>M;
  
  vector<vector<int>> vec(M,vector<int>(2));
  for(int i=0;i<M;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
 
  
  for(int i=0;i<M;i++){
    int sum=0;
    for(int i=0;i<N;i++){
      sum+=T[i];
    }
    sum=sum-T[vec[i][0]-1]+vec[i][1];
    cout<<sum<<endl;
  }
}