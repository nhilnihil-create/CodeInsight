#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b="CODEFESTIVAL2016";
    int ans=0;
    cin>>a;
    for(int i=0;i<b.size();i++)
    {
        if(a[i]!=b[i])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}