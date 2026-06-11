#include<bits/stdc++.h>
using namespace std;
int64_t f(vector<int64_t>a,int k){
int N=a.size();
  if(N<k)
  return 20000000000;
  else if(k==1){
  return 0;
  }else {
  if(a.at(0)<a.at(1)){
  a.erase(a.begin());
    return f(a,k-1);
  }else{
  int64_t t=a.at(0)+1-a.at(1);
    vector<int64_t>b=a;
    vector<int64_t>c=a;
    b.erase(b.begin());b.at(0)+=t; c.erase(c.begin()+1);
    return min(t+f(b,k-1),f(c,k));
  }
  
  }
 
}
int main(){
int N,K;
  cin>>N>>K;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int64_t ans=f(a,K);
  cout<<ans<<endl;
   return 0;
}