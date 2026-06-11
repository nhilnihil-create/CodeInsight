#include <bits/stdc++.h>

using namespace std;

int main(){
  
  long long int n;
  cin>>n;

  vector<long long> a(n);
  for(long long i=0; i<n; i++) cin>>a[i];
  sort(a.begin(), a.end());
  
  a.erase(unique(a.begin(), a.end()), a.end());

  if(a.size()%2!=0) cout<<a.size()<<endl;
  else if(a.size()%2==0) cout<<a.size()-1<<endl;

}
