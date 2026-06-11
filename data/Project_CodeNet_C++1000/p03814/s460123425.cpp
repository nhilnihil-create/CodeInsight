#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
ll a[3009][3009];
ll b[200003];
ll n,m;
bool vis[1009][1009];
struct threeElements{
int _1st,_2nd,_3rd;
};
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:15
   string s;
   cin>>s;
   int idx,idx1;
   bool f=0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='A'&&!f)
       {
           idx=i;
           f=1;
       }
    if(s[i]=='Z')
       {
           idx1=i;
       }
   }
   cout<<idx1-idx+1;
}
