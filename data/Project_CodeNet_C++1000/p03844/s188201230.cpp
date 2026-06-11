#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

typedef tree<int,null_type,less<int>,rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;

#define P pair<int,int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define st std::string 
#define pb push_back 
#define ll long long 
#define pq(x) std::priority_queue<x> 
#define ultapq(x) priority_queue<x,vector<x>,greater<x>> 
#define show_pq(x,n) for(int i = 0; i < n; i++){cout<<x.top(); x.pop();} 
#define itrt(yo) for(auto x:yo){std::cout<<x<<" ";} 
#define vec(x) std::vector<x> 
#define nl '\n' 
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define ALL(x) x.begin(),x.end() 
#define just int i= 0; i<n ; i++


void solve(){
    int a,b;
    char c;
    cin>>a>>c>>b;

    if (c=='-')
    {
        cout<<a-b;
    }else
    {
        cout<<a+b;
    }
    
    
}


int main()
{
    IOS;
    int t=1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    
}

    

    
	