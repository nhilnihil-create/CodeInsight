#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll dgt=-1;
	string tmp="1";
	REP(i,10) {
		cout<<"? "<<tmp<<endl;
		string ans;
		cin>>ans;
		if(ans=="N") {
			dgt=i;
			break;
		}
		tmp+="0";
	}
	if(dgt==-1) {
		string tmp2="9";
		REP(i,10) {
			cout<<"? "<<tmp2<<endl;
			string ans;
			cin>>ans;
			if(ans=="Y") {
				string ret="1";
				REP(j,(ll)tmp2.size()-1) ret+='0';
				cout<<"! "<<ret<<endl;
				return 0;
			}
			tmp2+="9";
		}
	} else {
		string lbs="1",ubs="10";
		REP(i,dgt-1) {
			lbs+='0';
			ubs+='0';
		}
		ll lb=stol(lbs),ub=stol(ubs);
		while(ub-lb>1) {
			ll mid=(lb+ub)/2;
			cout<<"? "<<mid*10<<endl;
			string ans;
			cin>>ans;
			if(ans=="N") lb=mid;
			else ub=mid;
		}
		cout<<"! "<<lb+1<<endl;
		return 0;
	}
}
