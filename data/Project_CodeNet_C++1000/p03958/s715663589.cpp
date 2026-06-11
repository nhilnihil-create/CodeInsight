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
	int k,t;cin>>k>>t;
	vector<int> a(t);
	for(int i = 0; i < t; i++) {
		cin>>a[i];
	}
	sort(ALL(a),greater<int>());
	if (a[0] <= (k +1) / 2){
		cout << 0 << endl;
	}
	else{
		cout << a[0] - 1 - (k - a[0]) << endl;
	}
	return 0;
}