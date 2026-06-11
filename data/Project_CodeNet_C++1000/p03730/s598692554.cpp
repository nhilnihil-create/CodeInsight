#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
struct threeElements{
int _1st,_2nd,_3rd;
};
vector<vector<int>>adj(10);
ll n;
bool check(string s,string t)
{
    int n1=s.length(),n2=t.length(),j=0;
    for(int i=0;i<n1;i++)
    {
        if(s[i]==t[j])
            j++;
        if(j==n2)
            return 1;
    }
    return 0;
}
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:52
    int i=1;
    int a,b,c;
    cin>>a>>b>>c;
    set<int>s;
    while(!s.count((a*i)%b))
        s.insert((a*i)%b),i++;
    if(s.count(c))
        cout<<"YES";
    else
        cout<<"NO";


}
