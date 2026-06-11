#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=str.size()-1;
 
    long long int ans=0;
    long long int temp=0;

    for (int bit =0;bit<(1<<n);++bit)
    {
        string strc=str;
        for (int i=0;i<n;++i)
        {
            if(bit&(1<<i))
            {
                strc.insert(n-i,"+");
            }
        }
   
        for (char j:strc)
        {
            if(j=='+')
            {
                ans+=temp;
                temp=0;
            }
            else
            {
                temp=temp*10+j-'0';
            }
        }
        ans+=temp;
        temp=0;
    }
    cout<<ans<<endl;
}

