#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t A,B,C;
  cin>>A>>B>>C;
  if(A%2==0 || B%2==0 || C%2==0)
    cout<<0<<endl;
  else{
  vector<int64_t>D(3);
    D[0]=A;
    D[1]=B;
    D[2]=C;
    sort(D.begin(),D.end());
    int64_t ans=D[0]*D[1];
    cout<<ans<<endl;
  
  
  }
   return 0;
}