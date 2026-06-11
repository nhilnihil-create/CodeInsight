#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n,m;cin>>n>>m;
	vector<int> a(n,0);
	for(int i = 0; i < m; i++) {
		int x,y;cin>>x>>y;
		a[x- 1]++;
		a[y - 1]++;
	}
	for(int i = 0; i < n; i++) {
		if (a[i] % 2 == 1){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}