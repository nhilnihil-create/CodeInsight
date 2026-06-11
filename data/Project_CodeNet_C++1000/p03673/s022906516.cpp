#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	int n; cin >> n;

	vector<int> a(n);
	REP(i,n) cin >> a[i];

	deque<int> deq;
	deq.push_back(a.front());


	FOR(i,1,n){
		if(n%2 == 1){
			if(i%2 == 0) deq.push_front(a[i]);
			else deq.push_back(a[i]);

		}else{
			if(i%2 == 0) deq.push_back(a[i]);
			else deq.push_front(a[i]);
		}
	}

	REP(i,n) cout << deq[i] << " ";
	cout << endl;



	return 0;

}
