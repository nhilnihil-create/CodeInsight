#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,ti,ai,k,l;
    cin>>n;
    
    i=1,j=1;
    while(n--)
    {
        cin>>ti>>ai;
  long long  x=(i-1)/ti+(long long)1,y=(j-1)/ai+(long long )1;
        k=max(x,y);
        i=ti*k,j=ai*k;
        
    }
    cout<<i+j;
}