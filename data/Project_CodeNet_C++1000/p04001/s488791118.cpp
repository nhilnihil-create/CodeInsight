#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;
  int k=s.size();
  long long ans=0;
  for(int tmp=0;tmp<pow(2,k-1);tmp++){
     bitset<9> t(tmp);
    long long a=0;
    for(int i=0;i<k;i++){
      
      long long h=s[i];
      h-=48;
      if(t[i]==0){
        a=10*a+h;
      }
      else{
        a=10*a+h;
        ans+=a;
        a=0;
      }
      if(i==k-1){
        ans+=a;
      }
        
    }
    
  }
  
 cout<<ans<<endl;
  
  
}
