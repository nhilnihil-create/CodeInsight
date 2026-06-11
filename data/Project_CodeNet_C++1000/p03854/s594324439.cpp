#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 500000000
#define IOS ios_base::sync_with_stdio(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;
vector<string>v;
string s;
bool match(int sx,int vx)
{
    for(int i=0;i<v[vx].size();i++)
        if(s[sx+i]!=v[vx][i])return 0;
    return 1;
}
int main()
{
    IOS;
    v.pb("dreameraser");
    v.pb("dreamerase");
    v.pb("dreamer");
    v.pb("dream");
    v.pb("eraser");
    v.pb("erase");
    int i=0;
    cin>>s;
    int l=s.length();
    while(i<l)
    {
        bool f=0;
        for(int j=0;j<v.size();j++)
        {
            if(match(i,j))
            {
                f=1;
//                cout<<"matched "<<v[j]<<endl;
                i+=v[j].size();
                break;
            }
        }
        if(f==0)break;
    }
    if(i==l)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
/*
dreamdreamerdreamerasereraseeraser
*/
