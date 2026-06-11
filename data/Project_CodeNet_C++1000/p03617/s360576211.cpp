#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	ll q,h,s,d;
	cin >> q >> h >> s >> d;
	ll n;
	cin >> n;
	ll one_l;
	one_l = min(q*4,h*2);
	one_l = min(one_l,s);
	if(one_l*2>d){
		if(n%2==1)
			cout << n/2*d+one_l << endl;
		else
			cout << n/2*d << endl;
	}
	else
		cout << n*one_l << endl;
	return 0;
}