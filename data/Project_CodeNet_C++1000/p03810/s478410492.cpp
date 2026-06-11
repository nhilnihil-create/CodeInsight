#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll gcd(ll a,ll b){
	if(a < b)swap(a,b);
	return b == 0 ? a : gcd(b,a%b);
}

int main(){

	int n;cin >> n;
	vector<int> v(n);
	int oddNum = 0;
	int evenNum = 0;
	REP(i,n){
		cin >> v[i];
		if(v[i] % 2)oddNum++;
		else evenNum++;
	}

	if(evenNum % 2){
		cout << "First" << endl;
	}
	else{
		int type = 0;
		while(oddNum == 1){
			bool flag = false;

			REP(i,n)if(v[i] > 1 && v[i] % 2){
				v[i]--;
				flag = true;
			}
			if(!flag)break;
			oddNum = 0;
			evenNum = 0;
			type++;
			ll gcdNum = v[0];
			REP(i,n)gcdNum = gcd(gcdNum,v[i]);
			REP(i,n){
				v[i] /= gcdNum;
				if(v[i] % 2)oddNum++;
				else evenNum++;
			}
			//SHOW1d(v,n);
		}

		if(evenNum % 2)type++;

		if(type % 2){
			cout << "First" << endl;
		}
		else {
			cout << "Second" << endl;
		}
	}
	return 0;
}
