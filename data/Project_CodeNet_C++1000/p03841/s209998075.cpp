#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 250200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
typedef std::pair<int,int> pr;
int n, x[maxn];
int ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	std::vector<pr> v;
	rep(i, 1, n) cin >> x[i], v.emplace_back(x[i], i);
	std::sort(v.begin(), v.end());
	for(auto i:v){ 
		int c=1;
		if(i.second>1) for(int j = 1;j < i.first;++j)
			if(!ans[j]) if(ans[j]=i.second,++c==i.second) break;
		if(c!=i.second||ans[i.first])return cout<<"No"<<'\n',0;
		ans[i.first]=i.second;
	}
	std::reverse(v.begin(), v.end());
	for(auto i:v){ 
		int c = n-i.second;
		if(c) for(int j = n * n;j > i.first;--j)
			if(!ans[j]) if(ans[j]=i.second,--c==0) break;
		if(c)return cout<<"No"<<'\n',0;
	}
	cout<<"Yes"<<'\n';
	rep(i,1,n*n)cout<<ans[i]<<' ';
}
