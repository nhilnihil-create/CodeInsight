#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int num=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=i;
            if(ans>=n)
            {
                num=i;
                break;
            }
        }
//        if(num==0) num=n;
        cout<<num<<endl;
    }
}
