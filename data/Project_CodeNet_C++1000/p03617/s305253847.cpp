#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  long a,b,c,d,n;
  cin >> a>>b>>c>>d>>n;
  if(n%2==0){
    long ans;
    ans=min(4L*a*n,2L*b*n);
    ans=min(ans,c*n);
    ans=min(ans,n/2*d);
    cout<<ans<<endl;
  }
  else{
    long ans;
    ans=min(4L*a*n,2L*b*n);
    ans=min(ans,c*n);
    ans=min(ans,n/2*d+ans/n);
    cout<<ans<<endl;
  }
  
}