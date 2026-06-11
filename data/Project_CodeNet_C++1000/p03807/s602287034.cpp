#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n,x,o=0;
    cin>>n;
    for(lld i=0;i<n;i++)
    {
        cin>>x;
        if(x%2!=0)o++;
    }
    if(o%2!=0)cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
}
