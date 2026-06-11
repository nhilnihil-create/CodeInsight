#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k;cin>>n>>k;
  vector<int64_t>a(100007,0);
  int ai,bi;
  for(int i=0;i<n;i++){
    cin>>ai>>bi;
    a.at(ai-1)+=bi;
  }
  for(int i=0;i<100007;i++){
    k-=a.at(i);
    if(k<=0){
      cout <<i+1<<endl;
      return 0;
    }
  }
}