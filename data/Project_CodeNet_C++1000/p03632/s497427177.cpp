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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b<=c || d<=a)
        cout<<"0\n";
    else
        cout<<min(b,d)-max(a,c)<<endl;
}