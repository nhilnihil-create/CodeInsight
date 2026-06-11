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
	ll n,k;cin>>n>>k;
	ll M = -1;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
		M = max(M,a[i]); 
	}
	ll G = a[0];
	for(int i = 1; i < n; i++) {
		G = __gcd(G,a[i]);
	}
	if(k <= M && k % G == 0){
		cout << "POSSIBLE" << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}