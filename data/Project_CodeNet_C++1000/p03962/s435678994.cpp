#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,a,b,c,ans;
    set<ll>color;
    cin>>a>>b>>c;
    color.insert(a);
    color.insert(b);
    color.insert(c);
    cout<<color.size()<<endl;


    return 0;
}



