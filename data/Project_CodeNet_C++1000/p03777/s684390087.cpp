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
    char a,b;
    cin>>a>>b;
    if (a=='H')
        cout<<b<<endl;
    else
    {
        if (b=='H')
            cout<<"D\n";
        else
            cout<<"H\n";
    }
}