#include <bits/stdc++.h>
using namespace std;





int main() {
  int64_t n;
  cin>>n;
  
  vector<int> prime(n+1,1);
  
  prime.at(0)=0;
  prime.at(1)=0;
  
  for (int i=2;i<=n;i++){
    if (prime.at(i)==1){
      for (int j=2*i;j<=n;j+=i){
        prime.at(j)=0;
      }
    }
  }
  

  
  int64_t answer=1;
  
  
  for (int i=1;i<=n;i++){
    int x=n;
    if (prime.at(i)==1){
      int64_t tmp=0;
      while (x>0){
        tmp+=x/i;
        x/=i;
      }
      

      answer*=(tmp+1)%(1000000007);
      answer=answer%1000000007;
    }
  }
      
      
      
        
  cout<<answer<<endl;
  
  
}










