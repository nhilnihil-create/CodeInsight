#include<bits/stdc++.h>
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
 template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
using namespace std;

const long long INF=9000000000000000;
int main(){
  int n,ans=0,x=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    ans+=i;
    x++;
    if(ans>=n)
      break;
  }
  for(int i=1;i<=x;i++){
    if(ans-n==i)
      continue;
    else
      cout<<i<<endl;
  }
}
