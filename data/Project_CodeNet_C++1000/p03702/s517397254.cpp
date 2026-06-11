#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cctype>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
//#include<windows.h>
//#include<time.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mer make_pair
#define mme memset
using namespace std;

const double pie1=3.1415926;//π1
const double pie2=3.14159265358979;//π2
const double pie3=3.14159265358979323846;//π3
const int vbi=999999999;
const int vli=-vbi;
const long long vbl=999999999999999999;
const long long vll=-vbl;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
typedef pair<pii,pii> pi4;
typedef pair<pll,ll> plll;
typedef pair<int,pii> ipii;
typedef pair<ll,pll> lpll;
typedef pair<pll,pll> pl4;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef set<int> sti;
typedef set<ll> stl;
typedef set<pii> spi;
typedef set<pll> spl;
priority_queue<int> pqi;
priority_queue<ll> pql;
queue<int> qi;
queue<ll> ql;

/*void bin_v(){
	char bin[1000];
	gets(bin);
}*/

bool pss(int a){
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return false;
	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////
int n,a,b;
ll h[100010];

bool ok(ll x){
	ll v=0;
	for(int i=1;i<=n;i++)
		if(h[i]>x*b){
			v+=ceil((h[i]-x*b)*1.0/a);
//			cout<<ll(ceil((h[i]-x*b)*1.0/a))<<' '<<h[i]-x*b<<endl;
		}
	return v<=x;
}

int main(){
	//my name is Veex_WCY
	ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	a=a-b;
	ll mosth=0;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		mosth=max(mosth,h[i]);
	}
	ll l=1,r=mosth,m;
	while(l<=r){
		m=(l+r)/2;
//		cout<<endl<<m<<endl;
		if(ok(m))
			r=m-1;
		else
			l=m+1;
	}
	cout<<l;
	return 0;
}
/*
900000000
900000000
1000000000
1000000000
1000000000
*/