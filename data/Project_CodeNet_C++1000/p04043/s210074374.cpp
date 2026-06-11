#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int a,b,c;
    map<int,int>p;
    cin>>a>>b>>c;
    p[a]++;p[b]++;p[c]++;
    if(p[5]==2&&p[7]==1)
        cout<<"YES";
    else
        cout<<"NO";
}
