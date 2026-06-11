#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second
 
vector<int> ans;
 
int main()
{
	ll targ;
	cin>>targ;
	++targ;
	bool s=0;
	vector<int> key; key.pb(1);
	for(int i=60; 0<=i; --i){
		int b=1&(targ>>i);
		if(!s && b) s=1;
		else if(s){
			if(b) key.pb(1);
			if(i) key.pb(0);
		}
	}
	reverse(all(key));
	int bot=1, top=key.size();
	cout << top*2 << endl;
	for(int i=1; i<=top; ++i) cout << i << ' ';
	for(int x:key){
		if(x == 1) cout << top-- << ' ';
		else cout << bot++ << ' ';
	}
	return 0;
}
