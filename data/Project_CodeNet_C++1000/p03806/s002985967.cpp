#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Khela ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
#define PII pair<ll ,ll>
 
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
const int Max=1e5+100;
const ll  MAX=1e18+500;
const int sz=1e3+100;
struct node
{
    int first,second,cost;
};
node ara[50];
int n,a,b;
int dp[45][500][500];
bool Check(int x,int y)
{
    if(x<=0 || y<=0) return false;
    int gc=__gcd(x,y);
    x/=gc,y/=gc;
    if(x==a && b==y)  return true;
    else return false;
}
int cholo(int id,int tota,int totb)
{
    if(id>=n){
        if(Check(tota,totb)) return 0;
        else return Max;
    }
    int &ret=dp[id][tota][totb];
    if(~ret)  return ret;
    int mx=ara[id].cost+cholo(id+1,tota+ara[id].first,totb+ara[id].second);
    mx=min(mx,cholo(id+1,tota,totb));
    return (ret=mx);
}
int main()
{
    Khela
    int c,i,j,k,q,p,x,y,ct,ct1,m,l,r,x1,y1,mn,h,sum1,in,z,mid,mx;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int t,cs=1;
    while(cin>>n>>a>>b)
    {
        for(i=0;i<n;i++) cin>>ara[i].first>>ara[i].second>>ara[i].cost;
        memset(dp,-1,sizeof dp);
        int ans=cholo(0,0,0);
        if(ans>=Max) cout<<"-1"<<endl;
        else cout<<ans<<endl;

    }





}