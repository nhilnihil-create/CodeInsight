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

ll N,ct,ans,pos;

ll M(int pos) {
	return (pos+1)/2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans=1;
	cin >> N;
	for (int i=0;i<N;i++) {
		ct++;
		cin >> pos;
		while (M(pos)<ct) {
			ans=ans*ct%mod;
			ct--;
		}
	}

	while (ct) {
		ans=ans*ct%mod;
		ct--;
	}

	cout << ans << endl;

}