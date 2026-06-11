#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int h,w,i=0;
    cin>>h>>w;
    string s[h];
    while(i<h)
    {
       cin>>s[i];
       i++;
    }
    for(int i=0;i<h;i++)
    {
       cout<<s[i]<<'\n'<<s[i];
       nl;
    }
    return 0;
}
