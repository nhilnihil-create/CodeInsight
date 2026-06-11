#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
int pri[1010];
const ll mod=1e9+7;
ll a[1010];
ll ans=1;
ll n;
ll cnt;
bool is_pri(ll m){
	for(int i=2;i<m;i++){
		if(m%i==0)return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(is_pri(i))pri[cnt++]=i,a[i]++;
		else {
			ll x=i;
			for(int j=0;j<cnt;j++){
				while(x%pri[j]==0){
					a[pri[j]]++;
					x/=pri[j];
				}
				if(x==1)break;
			}
		}
	}
	for(int i=0;i<cnt;i++)ans*=(a[pri[i]]+1),ans%=mod;
	cout<<ans;
	return 0;
}

