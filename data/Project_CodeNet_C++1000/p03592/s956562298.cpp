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
	int n,m,k;cin>>n>>m>>k;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if (i * m + j * n - 2 * i * j == k){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}