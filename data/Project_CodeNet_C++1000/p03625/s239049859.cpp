#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i;
    cin>>n;
    long long a[n],c[3],x=0;
    for(i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for(i=n-1;i>0;--i)
    {
        if(a[i]==a[i-1])
        {
            c[x]=a[i];
            --i;
            ++x;
        }
        if(x==2)
        {
            cout<<c[0]*c[1]<<endl;
            return 0;
        }
    }
      cout<<"0"<<endl;
      return 0;
}
