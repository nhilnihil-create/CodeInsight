/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 1e5+5 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG
int a[MAXN] ;
bool visited[MAXN] ;
int main()
{
    fio ;
    /* ======================Start of code ================ */
    int n;cin>>n;
    f(i,1,n+1) cin>>a[i] ;
    int steps = 0 ;
    int curr = 1 ;
    while(curr!=2 && !visited[curr])
    {   
        #ifdef DEBUG 
        is(curr) ;
        #endif 
    
        steps++ ;
        visited[curr] = 1 ;
        curr = a[curr] ;
    }
    if(curr==2) cout<<steps<<"\n" ;
    else cout<<"-1\n" ;
    /* ======================End of code ================== */
}