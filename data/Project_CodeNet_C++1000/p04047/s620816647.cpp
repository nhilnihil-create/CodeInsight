#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
  
  int n, m=0; cin>>n; n*=2;
  int s[n]; for(int &i:s) cin>>i;
  sort(s, s+n);
  for(int i=0; i<n-1; i+=2)
    m+=min(s[i], s[i+1]);
  
  cout<<m;
}