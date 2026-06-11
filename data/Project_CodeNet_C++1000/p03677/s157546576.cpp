#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
ll c[100005],k[100005];
int n,m;
ll a[100005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	for (int i=2;i<=n;++i){
		ll x=a[i-1],y=a[i];
		if (x<y){
			c[0]+=y-x;
			c[x+1]-=y-x;
			c[x+1]+=y+1;k[x+1]-=1;
			c[y+1]-=y+1;k[y+1]+=1;
			c[y+1]+=y-x;
			c[m+1]-=y-x;
		}
		else{
			c[0]+=y+1;k[0]-=1;
			c[y+1]-=y+1;k[y+1]+=1;
			c[y+1]+=m+y-x;
			c[x+1]-=m+y-x;
			c[x+1]+=m+y+1;k[x+1]-=1;
			c[m+1]-=m+y+1;k[m+1]+=1;
		}
	}
	ll mn=1e15;
	for (ll i=1;i<=m;++i){
		c[i]+=c[i-1];k[i]+=k[i-1];
		//cout<<"i:"<<i<<"  "<<c[i]<<"  "<<k[i]<<endl;
		mn=min(mn,c[i]+k[i]*i);
	}
	cout<<mn;
	return 0;
}