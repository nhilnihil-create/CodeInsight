#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std ;

int main()
{
    int n;
    cin>>n;
    int a[n],tem,count[n],k=0,ans=0;

    memset(count,1,sizeof(count));

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            count[k]++;
        }
        else
            k++;
    }

    for(int j=0;j<k;j++)
    {
        if(count[j]%2==1)
        {
            ans++;
        }
    }
    cout<<ans<<endl ;
    return 0;
}
