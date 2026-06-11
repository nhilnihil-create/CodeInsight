#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int n;
  cin>>n;

  long long int l, r;
  cin>>l>>r;

  for(int i=1; i<n; i++){
    long long int t, a;
    cin>>t>>a;
    long long int j=max((l-1)/t, (r-1)/a)+1;
 //   while(j*t<l or j*a<r) j++;
    l=j*t;
    r=j*a;
  }

  cout<<l+r<<endl;
}
