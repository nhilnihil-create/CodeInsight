#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

int N;
int a[100000];

int solve() {
	int nodd=0,sum=0,oi;
	bool s1=0;
	for (int i=0;i<N;i++) {
		sum^=a[i]-1;
		if (a[i]&1) nodd++,oi=i;
		if (a[i]==1) s1=1;
	}
	if (nodd>1 || (sum&1) || s1) return sum&1;

	a[oi]--;
	int g=0;
	for (int i=0;i<N;i++) g=__gcd(g,a[i]);
	for (int i=0;i<N;i++) a[i]/=g;

	return !solve();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> a[i];
	}

	if ((N==1 && a[0]>1) || (N>1 && solve())) cout << "First\n";
	else cout << "Second\n";

}