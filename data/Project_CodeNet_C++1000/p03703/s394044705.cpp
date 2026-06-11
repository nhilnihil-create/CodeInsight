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

inline void checkmin(int &x, int y){x = min(x, y);}
inline void checkmax(int &x, int y){x = max(x, y);}

int n,k;
int a;

vl pref;

struct SegTree
{
	int len=0;
	vl s;
	vl tree;
	void init()
	{
		len=1;
		while(len<=sz(s)) len<<=1;
		while(sz(s)<len) s.PB(s.back());
		tree.rsz(len*2,0);
	}
	void change(ll k,int d)
	{
		int i=lb(all(s),k)-begin(s)+len;
		while(i>0)
		{
			tree[i]+=d;
			i>>=1;
		}
	}
	ll get(int x,int l,int r,ll k)
	{
		if(s[r-1]<k) return 0;
		if(s[l]>=k) return tree[x];
		int mid=(l+r)>>1;
		return get(x*2,l,mid,k)+get(x*2+1,mid,r,k);
	}
}box;

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
    pref.PB(0);
    box.s.PB(0);
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	pref.PB(pref.back()+a-k);
    	box.s.PB(pref.back());
	}
	box.init();
	sort(all(box.s));
//	for(int i=0;i<sz(box.s);i++) cout<<box.s[i]<<" ";
//	cout<<endl;
	ll ans=0;
	for(int i=n;i>=0;i--)
	{
		ans+=box.get(1,0,box.len,pref[i]);
		box.change(pref[i],1);
	}
	cout<<ans<<endl;
    /* end code */
	return 0;
}