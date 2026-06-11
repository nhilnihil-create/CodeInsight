#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  i,j,cur=0,t,k,a,b,c=0;
    cin>>a>>b;
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=a;j++)
        {
            cur=b-(i+j);
            if(cur>=0&&cur<=a)
               c++;
        }
    }
    cout<<c<<"\n";


return 0;
}
