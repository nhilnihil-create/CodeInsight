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
    int a,b;
    cin>>a>>b;
    if (a==1 && b==1)
        cout<<"Draw\n";
    else if (a==b)
        cout<<"Draw\n";
    else if (a==1 && b!=1)
        cout<<"Alice\n";
    else if (a!=1 && b==1)
        cout<<"Bob\n";
    else if (a>b)
        cout<<"Alice\n";
    else if (a<b)
        cout<<"Bob\n";
}
