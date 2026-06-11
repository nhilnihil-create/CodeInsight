#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    while(cin>>a[0]>>a[1]>>a[2])
    {
        int sum1=0,sum2=0,i;

        for(i=0;i<3;i++)
        {
            if(a[i]==5)
                sum1++;
            if(a[i]==7)
                sum2++;
        }
        if((sum1==2) && (sum2==1))
           cout<<"YES\n"<<endl;
           else
            cout<<"NO\n"<<endl;
    }
    return 0;
}
