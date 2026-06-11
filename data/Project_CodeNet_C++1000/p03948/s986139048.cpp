#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int tree[400009],ar[100009] ;
vector<pii>v ;
void build(int p , int lo , int hi)
{
    if(lo==hi){tree[p]=ar[lo] ; return ; }
    int md=(lo+hi)/2 ;
    build(p*2,lo,md) ;
    build(p*2+1,md+1,hi) ;
    tree[p]=max(tree[p*2],tree[p*2+1]) ;
}
int query(int p , int lo , int hi , int l , int r)
{
    if(lo>=l && hi<=r) return tree[p] ;
    if(l>hi || r<lo) return 0 ;
    int md=(lo+hi)/2 ;
    int x=query(p*2,lo,md,l,r) , y=query(p*2+1,md+1,hi,l,r) ;
    return max(x,y) ;
}
int main()
{
    int n,t,mx=-1 ; cin>>n>>t ;
    for(int i = 1 ; i <= n ; i++) cin>>ar[i] ;
    build(1,1,n) ;
    for(int i = 1 ; i < n ; i++)
    {
        int x=ar[i] ;
        int y=query(1,1,n,i+1,n) ;
        if(y-x>0 && y-x>mx)
        {
            mx=y-x ;
            v.clear() ; v.push_back({y,x}) ;
        }
        else if(y-x>0 && y-x==mx) v.push_back({y,x}) ;
    }
    cout<<v.size()<<endl ;
}
