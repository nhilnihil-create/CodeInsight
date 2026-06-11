#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >>N>>M;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    vec.at(i)=0;
  }
  for(int i=0;i<M;i++){
    int a,b;
    cin >>a>>b;
    a-=1;
    b-=1;
    vec.at(a)+=1;
    vec.at(b)+=1;
  }
  
  for(int i=0;i<N;i++){
    cout <<vec.at(i)<<endl;
  }
}