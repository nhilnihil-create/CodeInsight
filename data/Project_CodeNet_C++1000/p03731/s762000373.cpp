#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n, t;
  cin>>n >>t;
  long long x=t;
  vector<long long> s(n);
  for(int i=0;i<n;i++)cin>>s[i];
  
  for(int i=0;i<n-1;i++){
    x+=min(s[i+1]-s[i], t);
  }
  
  cout<<x<<endl;
  return 0;
}