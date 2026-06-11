#include<bits/stdc++.h>
using namespace std; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int x,c1=0,c2=0;
    for(int i=0;i<3;i++)
    {
        cin>>x;
        if(x==5)
        c1++;
        if(x==7)
        c2++;
    }
    if(c1==2&&c2==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
