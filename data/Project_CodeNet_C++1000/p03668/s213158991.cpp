/*

    author : s@if

*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define 		NIL 			-1
#define		 	fi	 		    first
#define 		sec 			second
#define 		MAX 			INT_MAX
#define			INF 			1e9
#define 		ll 			    long long
#define 		PI 			    acos(-1.0)
#define			MOD 			1000000007
#define 		PLL 			pair<ll,ll>
#define 		PII			    pair<int,int>
#define 		ull 			unsigned long long
#define 		For(i,a,b) 		for(int i=a;i<=(int)b;i++)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;


inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos)	{	return (bool) (N & (1<<pos));}
int Set(int N, int pos) {	return N = N | (1<<pos);}

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};    // King's move
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hx[]={-2,-2,-1,+1,+2,+2,-1,+1};    // Knight's move
int hy[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

const int MAXN = (int)2e5+9;

vector<int>adj[MAXN];
int dp[MAXN];

void dfs(int curr, int prev = -1)
{
    dp[curr] = 0;

    for(int i=0; i<adj[curr].size(); i++)
    {
        int v = adj[curr][i];
        if(v!=prev){
            dfs(v, curr);
            dp[curr]^=1+dp[v];
        }
    }
}

int main()
{
/*	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); */

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i,j,k,l,m,n,p,q,x,y,u,v,r,tc,t;

    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    if(dp[1]>0){
        cout<<"Alice\n";
    }else{
        cout<<"Bob\n";
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
