#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
//8c:1a:bf:89:66:b6
struct threeElements{
int _1st,_2nd,_3rd;
};
vector<vector<int>>adj(10);
ll v[200009];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:52
    string s,t;
    cin>>s>>t;
    if(s.length()>t.length())
        cout<<"GREATER";
    else if(s.length()<t.length())
        cout<<"LESS";
    else
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            {
                if(s[i]>t[i])
                    return cout<<"GREATER",0;
                else
                    return cout<<"LESS",0;
            }
        }
        cout<<"EQUAL";
    }
}
