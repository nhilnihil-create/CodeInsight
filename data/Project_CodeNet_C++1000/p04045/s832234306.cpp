#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int A_78(long long n)
{
    while(n!=0)
    {
        if(arr[n%10]==1)
            return 0;
        n=n/10;
    }
    return 1;
}
int main()
{
    long long n,p,i,j,k,l;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>l;
        arr[l]=1;
    }
    for(j=n;j<1000006;j++)
    {
        if(A_78(j))
        {
            cout<<j<<endl;
            break;
        }
    }
    cout<<endl;
}
