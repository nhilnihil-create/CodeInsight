//BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define pi acos(-1.00)

using namespace std;



int main()
{
int n,m,i;
cin>>n>>m;
    string s[200];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n);
    for(i=0;i<n;i++)
        cout<<s[i];

}

