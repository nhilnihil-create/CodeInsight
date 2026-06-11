#include<bits/stdc++.h> 

using namespace std;

typedef short sho;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str; 
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll; 
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<pld> vpd;

#define STDIO
#define MP make_pair 
#define FF first
#define SS second
#define sz(x) (int)x.size()
#define begin(x) (x).begin() 
#define end(x) (x).end()
#define rbegin(x) (x).rbegin()
#define rend(x) (x).rend()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define PF push_front 
#define PB push_back
#define PP push
#define lb lower_bound
#define ub upper_bound
#define lowbit(x) x&-x

inline void checkmin(int &x, int y){x = min(x, y);}
inline void checkmax(int &x, int y){x = max(x, y);}

const int Maxn=2e5+10;

class BIT
{
	public:
		int bita[Maxn];
		void add(int pos,int x)
		{
			pos++;
			while(pos<Maxn)
			{
				bita[pos]+=x;
				pos+=lowbit(pos);
			}
		}
		int get(int pos)
		{
			pos++;
			int ans=0;
			while(pos>0)
			{
				ans+=bita[pos];
				pos-=lowbit(pos);
			}
			return ans;
		}
}bit;

int n;
ll k;
ll a[Maxn];

ll PreSum[Maxn];
vl v;

int main() 
{
	#ifndef STDIO
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /* start code */
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) PreSum[i]=PreSum[i-1]+a[i]-k;
    for(int i=1;i<=n;i++) v.PB(PreSum[i]);
    sort(all(v));
    v.erase(unique(all(v)),end(v));
//  for(int i=0;i<sz(v);i++) cout<<v[i]<<' ';
//  cout<<endl;
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
//    	cout<<PreSum[i]<<endl;
    	int pos=lb(all(v),PreSum[i])-begin(v);
//    	cout<<pos<<endl;
    	ans+=bit.get(pos);
    	bit.add(pos,1);
	}
	cout<<ans<<endl; 
    /* end code */
	return 0;
}