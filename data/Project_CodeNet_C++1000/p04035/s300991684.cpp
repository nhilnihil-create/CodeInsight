#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	ll N,L;
	cin >> N >> L;
	vector<ll> A(N),ans;
	rep(i,N)cin >> A[i];
	int start = -1;
	rep(i,N-1){
		if(A[i]+A[i+1] >=L){
			start = i;
			break;
		}
	}
	ans.push_back(start);
	for(int i=start+1;i<N-1;i++)ans.push_back(i);
	for(int i=start-1;i>=0;i--)ans.push_back(i);
	reverse(ALL(ans));
	if(start !=-1){
		cout << "Possible" << endl;
		for(auto x:ans)cout << x+1 << endl;
	}else cout <<"Impossible" << endl;
}