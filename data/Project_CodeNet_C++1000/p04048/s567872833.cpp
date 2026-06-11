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
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
ll n,x;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>x;
	ll ans=0;
	ans+=n;
	ll a=x,b=n-x;
	while(a!=b){
		if (a<b) swap(a,b);
		ll k=a/b;
		if (a%b==0) --k;
		ans+=b*2*k;
		a-=b*k;
	}
	ans+=a;
	cout<<ans<<endl;
	return 0; 
}