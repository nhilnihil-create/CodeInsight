#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

ll d[200010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n,t; cin>>n>>t;

	rep(i,n){
		cin>>d[i];
	}

	ll sum =0;
	ll firstputh =d[0];
	ll secondputh =d[0];
	for(int i=1; i<n; i++){

		if(secondputh+t >=d[i]){
			secondputh =d[i];
		}else {
			sum +=  (secondputh-firstputh)+t;
			firstputh = d[i];
			secondputh = d[i];

		}

	}
	sum += (secondputh-firstputh)+t;

	writeln(sum);
}
