#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)


int main(){
 long n,k;
   cin >> n >> k;
 vector<long> s(n+1,0),t(n+1,0);
  rep(i,0,n) {
    long a;
    cin >> a;
   s[i+1]=s[i]+a;
   t[i+1]=t[i]+max(long(0),a);
  
  }
 
  long res=0;
  rep(i,0,n-k+1){
   res=max(res,t[i]+max(s[i+k]-s[i],long(0))+(t[n]-t[i+k]));
  }
 
  cout << res << endl;
  
 
}