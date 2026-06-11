/*
  In The Name Of GOD
  author: amirhoseinatari
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define pp() pop_back()
#define mp make_pair
#define fir first
#define sec second
#define momaz(x) cout.precision(x);cout<<fixed
#define _ ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define debug(x) cout<<string(20,'#')<<endl<< #x <<"--> "<<x<<endl<<string(20,'-')<<endl
#define debug1(x) cout<<string(20,'#')<<endl<< #x <<"--> "<<x<<endl<<string(20,'-')<<endl
#define debug2(x,y) cout<<string(20,'#')<<endl<< #x <<"--> "<<x<<endl<< #y <<"--> "<<y<<endl<<string(20,'-')<<endl
#define debug3(x,y,z) cout<<string(20,'#')<<endl<< #x <<"--> "<<x<<endl<< #y <<"--> "<<y<<endl<< #z <<"--> "<<z<<endl<<string(20,'-')<<endl
#define debug4(x,y,z,t) cout<<string(20,'#')<<endl<< #x <<"--> "<<x<<endl<< #y <<"--> "<<y<<endl<< #z <<"--> "<<z<<endl<< #t <<"--> "<<t<<endl<<string(20,'-')<<endl
///freopen("input.txt","r",stdin);   add to main()
///freopen("output.txt","w",stdout);     //

/*
</head>
<body>
*/

const ll maxn = 100050 ;
vi a[maxn];

int dfs(int v,int par)
{
    int ans=0;
    for(auto i:a[v])
    {
        if(i!=par)
            ans^=dfs(i,v)+1;
    }
    return ans;
}
int main()
{_
	int n,q1,q2;
	cin>>n;
	for(int i=1;i<n;i++)
        cin>>q1>>q2,a[q1].pb(q2),a[q2].pb(q1);
    if(dfs(1,-1)==0)
        cout<<"Bob";
    else
        cout<<"Alice";

    return 0;
}
///Attar81 :)