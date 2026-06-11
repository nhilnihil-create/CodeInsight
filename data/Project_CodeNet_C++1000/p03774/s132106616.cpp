#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M;
  cin>>N>>M;
  
  vector<vector<int>> S(N,vector<int>(2));
  for(int i=0;i<N;i++){
    cin>>S[i][0]>>S[i][1];
  }
  
  vector<vector<int>> check(M,vector<int>(2));
  for(int j=0;j<M;j++){
    cin>>check[j][0]>>check[j][1];
  }
  
  
  for(int i=0;i<N;i++){
    long long res=1000000000000000000;
    for(int j=0;j<M;j++){
      long long D=abs(check[j][0]-S[i][0])+abs(check[j][1]-S[i][1]);
      res=min(res,D);
    }
    for(int j=0;j<M;j++){
      if((abs(check[j][0]-S[i][0])+abs(check[j][1]-S[i][1]))==res){
        cout<<j+1<<endl;
        break;
      }
    }
  }
}