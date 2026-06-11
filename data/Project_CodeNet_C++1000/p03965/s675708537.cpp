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
    int i,tp=0,w=0,l=0;
    for (i=0;i<s.size();i++)
    {
        if (s[i]=='g')
        {
            if (tp>0)
            {
                tp--;
                w++;
            }
            else
                tp++;
        }
        else
        {
            if (tp>0)
                tp--;
            else
            {
                tp++;
                l++;
            }
        }
    }
    cout<<w-l<<endl;
}