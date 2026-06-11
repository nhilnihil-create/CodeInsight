/*input

*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

int main(){
	IOS;
	{
		cout<<"? 10000000000"<<endl;
		string type;
		cin>>type;
		if(type[0]=='Y'){
			string tmp="2";
			while(1){
				cout<<"? "<<tmp<<endl;
				string an;
				cin>>an;
				if(an[0]=='Y'){
					tmp[0]='1';
					cout<<"! "<<tmp<<endl;
					return 0;
				}
				tmp.pb('0');
			}
		}
	}

	int len=0;
	{
		string tmp="1";
		while(len<15){
			len++;
			cout<<"? "<<tmp<<endl;
			string an;
			cin>>an;
			if(an[0]=='Y');
			else break;
			tmp.pb('0');
		}
	}
	len--;


	ll l=1,r=1;
	REP(I,len-1) l*=10;
	r=l*10-1;
	while(l!=r){
		ll mid=(l+r)/2;
		// cout<<l<<' '<<r<<endl;
		cout<<"? "<<mid<<'9'<<endl;
		string an;
		cin>>an;
		if(an[0]=='Y') r=mid;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
	return 0;
}
