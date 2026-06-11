#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
set<pair<int,int>>sp[20],st,yo ;
pair<int,int>ar[100009] ;
int n,m,k,ans[12] ;
map<pair<int,int>,int>mp ;
bool check(int x , int y , int ct)
{
    if(x+2>n || y+2>m) return 0 ;
    int cc=0 ;
    for(int i = x ; i <= x+2 ; i++)
    {
        for(int j = y ; j <= y+2 ; j++)
        {
            if(st.find({i,j})!=st.end()) cc++ ;
        }
    }
    if(cc) sp[cc].insert({x,y}) ;
    if(cc) yo.insert({x,y}) ;
    return cc==ct ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    cin>>n>>m>>k ;
    for(int i = 0 ; i < k ; i++)
    {
        cin>>ar[i].F>>ar[i].S ;
        st.insert({ar[i].F,ar[i].S}) ;
    }
    //sort(ar,ar+k) ;
    for(int i = 0 ; i < k ; i++)
    {
        int x=ar[i].F,y=ar[i].S ;
        int p,q,r,s ;
        p=x ; q=y ;
        if(p-1>=1) p-- ; if(p-1>=1)p-- ;
        if(q-1>=1) q-- ; if(q-1>=1)q-- ;
        for(int i1 = p ; i1 <= x ; i1++)
        {
            for(int j1 = q ; j1 <= y ; j1++)
            {
                check(i1,j1,0);
            }
        }
    }
    for(int i = 1 ; i < 10 ; i++) ans[i]=sp[i].size() ;
    int tot=(n*m)-(2*m)-(2*n)+4 ;
    ans[0]=tot-yo.size() ;
    for(int i = 0 ; i < 10 ; i++) cout<<ans[i]<<endl ;
}
