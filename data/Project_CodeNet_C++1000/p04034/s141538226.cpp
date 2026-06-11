#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(N,1);
  set<int> B;
  B.insert(0);
  int r=0;
  for(int i=0;i<M;i++){
    int x,y;
    cin>>x>>y;
    if(B.count(x-1)){
      if(A[x-1]==1){
        B.erase(x-1);
      }
      B.insert(y-1);
    }
    A[x-1]--;
    A[y-1]++;
  }
  cout<<B.size()<<endl;
}