#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,m,p,x,sum=0;
    string a,b,c;
    cin>>a>>b>>c;
    if(a[a.length()-1]==b[0]&&b[b.length()-1]==c[0])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}



