#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
ll a[200003];
ll b[2003];
bool vis[1009][1009];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
    cin>>sx>>sy>>tx>>ty;
    int x=tx-sx,y=ty-sy;
    for(int i=0;i<x;i++)
    {
        cout<<"R";
    }
    for(int i=0;i<y;i++)
        cout<<"U";
    for(int i=0;i<x;i++)
        cout<<"L";
    for(int i=0;i<y;i++)
        cout<<"D";
    cout<<"D";
    for(int i=0;i<x;i++)
        cout<<"R";
    cout<<"R";
    for(int i=0;i<y;i++)
        cout<<"U";
    cout<<"ULU";
    for(int i=0;i<x;i++)
        cout<<"L";
    cout<<"L";
    for(int i=0;i<y;i++)
        cout<<"D";
    cout<<"DR";


}
