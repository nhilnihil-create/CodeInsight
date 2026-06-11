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

int main(){
	
	ll n;cin >> n;

	deque<int> deq;
	deq.push_front(1);
	deque<int> v;
	
	while(n != 1){
		if(n % 2 == 0){
			v.push_front(1);
			n--;
		}
		else {
			v.push_front(0);
			n--;
			n /= 2;
		}
	}
	
	REP(i,v.size()){
		if(v[i]){
			deq.push_front(i+2);
		}
		else {
			deq.push_back(i+2);
		}
	}
	
	cout << 2*(v.size()+1) << endl;
	REP(i,v.size()+1)cout << i+1 << ' ';
	REP(i,v.size()+1){
		cout << deq[i];
		if(i != v.size()+1 - 1)cout << ' ';
	}
	cout << endl;
	
	return 0;
}
