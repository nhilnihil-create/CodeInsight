#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,a[50],sum=0,c=1;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=n-1;i>=0;i--){
 if(c<=k){
        sum+=a[i];
        c++;
 }
  else break;

  }
  cout<<sum;
    return 0;

}
