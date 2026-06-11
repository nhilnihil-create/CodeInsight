#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],i,c=1;
    for(i=0;i<3;i++) cin>>a[i];
    sort(a,a+3);
    for(i=0;i<2;i++)
    {
        if(a[i]==a[i+1]) continue;
        else c++;
    }
    cout<<c<<endl;
    return 0;
}

