#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int n,x=0,mx=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='I')
            x++;
        else
            x--;
        mx=max(x,mx);
    }
    cout<<mx;
    nl;
    return 0;
}
