#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long i,n,c=0,k;
    cin>>n>>k;
    long long A[n];
    for(i=0;i<n;i++)
      cin>>A[i];
      sort(A,A+n);

    for(i=n-1;i>=(n-k);i--)
    {
      c+=A[i];
    
    }
  cout<<c<<endl;


  return 0;
}
