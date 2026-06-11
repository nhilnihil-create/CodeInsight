#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],r,r1,rez=1000000000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        r+=a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        r1+=a[i];
        if(abs(r1-(r-r1))<rez)
            rez=abs(r1-(r-r1));
    }

    cout<<rez<<endl;

    return 0;
}
