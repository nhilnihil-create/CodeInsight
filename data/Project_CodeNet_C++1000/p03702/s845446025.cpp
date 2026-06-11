#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N;
ll A,B;
ll h[SIZE];

bool check(ll n){
	ll cnt=0;
	rep(i,0,N){
		ll now = max(0LL,h[i]-B*n);
		cnt += (now+A-1)/A;
	}
	//cout << n << " " << cnt << endl;
	return cnt <= n;
}

int main()
{
	cin >> N >> A >> B;
	A -= B;
	rep(i,0,N)cin >> h[i];
	ll l=-1,r=INF;
	while(r-l>1){
		ll m = (l+r)/2;
		if(check(m))r = m;
		else l = m;
	}
	cout << r << endl;
	return 0;
}
