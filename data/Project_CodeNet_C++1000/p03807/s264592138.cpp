#include <bits/stdc++.h>
using namespace std;


int main() {
  int64_t N;
  cin>>N;
  
  int64_t K=0;
  int64_t G=0;
  for(int i=0;i<N;i++){
    int64_t a;
    cin>>a;
    if(a%2==0) G++;
    else K++;
  }
  if(K==1&&G==0){
    cout<<"YES"<<endl;
    return 0;
  }
  if(K%2==1){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
      
  }
}