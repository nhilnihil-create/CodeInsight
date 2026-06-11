#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    string s;
    cin>>s;
    int n=s.size(),i,f=0;
    pair<int,int> ans={-1,-1};
    for (i=0;i<n-1;i++)
    {
        if (s[i]==s[i+1])
        {
            ans.ff=i+1;
            ans.ss=i+2;
            f=1;
            break;
        }
    }
    if (f)
        cout<<ans.ff<<" "<<ans.ss<<endl;
    else
    {
        for (i=0;i<n-2;i++)
        {
            if (s[i]==s[i+2])
            {
                ans.ff=i+1;
                ans.ss=i+3;
                break;
            }
        }
        cout<<ans.ff<<" "<<ans.ss<<endl;
    }
}