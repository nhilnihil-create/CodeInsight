#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

ll gcd( ll a, ll b){
	if(b ==0) return a;

	 return gcd(b , a%b);
}

ll lcm(ll a, ll b){

	return a*(b/gcd(a,b));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin>>n;

	ll cnt =0;

	ll twocnt =0;
	rep(i,n){
		ll tmp; cin>>tmp;
		if(tmp %4 ==0)cnt++;
		if(tmp %2 ==0 && tmp% 4 !=0)twocnt++;
	}
	if(twocnt ==n){
		writeln("Yes");
		return 0;
	}
	int c =0;
	if(twocnt >=2){
		c = -twocnt+1;
	}

	if(n-cnt +c<= cnt+1 && cnt !=0 ){
		writeln("Yes");
	}else {
		writeln("No");
	}




}
