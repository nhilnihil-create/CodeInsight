#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m;cin>>n>>m;

	if(abs(n-m) >=2){
		writeln(0);
		return 0;
	}


	ll a =1;
	ll b =1;

	for(int i=1; i<=n; i++){
		 a *=i;

		 a %= 1000000007;
	}
	for(int i=1; i<=m; i++){
		 b *=i;

		 b %= 1000000007;
	}
	if(n==m){
	writeln((2*a*b)%1000000007);
	}else {
		writeln((a*b)%1000000007);
	}
}
