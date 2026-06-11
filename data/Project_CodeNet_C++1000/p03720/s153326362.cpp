//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,j,k,l,n,m;
    cin>>n>>m;
    ll a[n],x,y;
    memset(a,0,sizeof(a));
    while(m--)
    {
        cin>>x>>y;
        a[x-1]++;
        a[y-1]++;
    }
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;

    return 0;
}



