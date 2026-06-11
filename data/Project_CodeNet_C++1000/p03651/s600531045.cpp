#include<bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t x,int64_t y){
if(y==0)
  return x;
  else
    return gcd(y,x%y);
}
int main(){
int N; int64_t K;
  cin>>N>>K;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  int64_t g=A.at(0);
  for(int i=1;i<N;i++)
    g=gcd(g,A.at(i));
  if(K%g!=0)
    cout<<"IMPOSSIBLE"<<endl;
  else{
  if(K<=A.at(N-1))
    cout<<"POSSIBLE"<<endl;
    else
      cout<<"IMPOSSIBLE"<<endl;
  
  }
  
   return 0;
}
