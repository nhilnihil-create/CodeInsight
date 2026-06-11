#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
int main()
{
    ///"In the name of Allah,most gracious and most merciful"///

    ll i,j,y,count=1,sum=0,n,ans=0;
    string s;
    cin>>s;

    for(i=s.size()-3; i>=0; i-=2)
    {
        string w,q;
        ll x;
        x=i/2;
        w=s.substr(0,x);
        q=s.substr(x+1,x);
        if(w==q)
        {
            y=x+x;
            break;
        }

    }
    cout<<y+2<<endl;

    return 0;
}




