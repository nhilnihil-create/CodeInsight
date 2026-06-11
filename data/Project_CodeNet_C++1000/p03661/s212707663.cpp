#include <bits/stdc++.h>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long> s(n+1,0);
  
  for(int i=1;i<=n;i++){
   long a;
    cin >> a;
    s[i]=a+s[i-1];
  }
 
  long res=1000000000000000;
  for(int i=1;i<n;i++){
   res=min(abs(2*s[i]-s[n]),res);
  }
  
  cout << res << endl;
  
}