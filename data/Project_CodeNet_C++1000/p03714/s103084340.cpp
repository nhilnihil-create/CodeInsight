
// Problem : D - 3N Numbers
// Contest : AtCoder - AtCoder Beginner Contest 062
// URL : https://atcoder.jp/contests/abc062/tasks/arc074_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define eb emplace_back
#define pb push_back
#define size(s) (int)s.size()
#define int long long
#define vi vector<int>
#define vs vector<string>
#define vv vector<vector<int>>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define inc(v,n,x) v.assign(n,x)
#define incd(v,n) v.resize(n)
#define iniz(n) memset(n,0,sizeof(n))
#define inin(n) memset(n,-1,sizeof(n))
#define inimi(n) memset(n,0xc0,sizeof(n))
#define inima(n) memset(n,0x3f,sizeof(n))
#define all(v) (v).begin(),(v).end()

using namespace std;

template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }

const int N=200001;
double pi=acos(-1.0);
const int md=1e9+7;
const int INF=1e15;
int dx1[]={0,0,-1,1};
int dy1[]={1,-1,0,0};

template<class T>
T abst(T a)
{return a<0?-a:a;}

template<class T>
T max2(T a,T b){return a>b?a:b;}
template<class T>
T min2(T a,T b){return a<b?a:b;}
int n;
vi v;
int dp[3001][1001];
int fun(int i,int rem)
{
	if(i==3*n) return rem==n?0:-INF;
	if(dp[i][rem]!=INF)return dp[i][rem];
	int x=i-rem;
	int ans=-INF;
	ans=max2(ans,((x<n)?v[i]:-v[i])+fun(i+1,rem));//pick the element
	if(rem<n)
	ans=max2(ans,fun(i+1,rem+1));
	return dp[i][rem]=ans;
}
void solve()
{
cin>>n;
incd(v,3*n+1);
for(int i=1;i<=3*n;i++)cin>>v[i];
vi left(3*n+1),right(3*n+1);
multiset<int> s;
int cnt=0;
for(int i=1;i<=n;i++)
{
	cnt+=v[i];
	s.insert(v[i]);
}
left[n]=cnt;
for(int i=n+1;i<=2*n;i++)
{
	left[i]=left[i-1];
	if(*s.begin()<v[i])
	{
		left[i]+=v[i]-*s.begin();
		s.erase(s.begin());
		s.insert(v[i]);
	}
}
multiset<int,greater<int>> s2;
cnt=0;
for(int i=3*n;i>=2*n+1;i--)
{
	cnt+=v[i];
	s2.insert(v[i]);
}
right[2*n]=cnt;
for(int i=2*n-1;i>=n;i--)
{
	right[i]=right[i+1];
	if(v[i+1]<*s2.begin())
	{
		right[i]+=(v[i+1]-*s2.begin());
		s2.erase(s2.begin());
		s2.insert(v[i+1]);
	}
}
int ans=-INF;
for(int i=n;i<=2*n;i++)
ans=max2(ans,left[i]-right[i]);
cout<<ans;
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int t=1;
//cin>>t;
for(int i=1;i<=t;i++)
{
    solve();
}
return 0;
}
