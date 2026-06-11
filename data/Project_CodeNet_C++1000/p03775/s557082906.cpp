#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A;cin>>A;
  for(int i=sqrt(A);;i--){
    if(A%i==0){
      int ans=log10(A/i);
      cout<<ans+1<<endl;
      return 0;
    }
  }
}