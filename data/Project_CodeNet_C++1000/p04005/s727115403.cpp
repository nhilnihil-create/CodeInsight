#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll a, b, c, ans=0;
	cin >> a >> b >> c;
	
	if(a >= b && a>= c){
		int m = a/2;
		ans= (b*c)*(a-2*m);
	}
	else if( b >= c){
		int m = b/2;
		ans= (a*c)*(b-2*m);
	}
	else{
		int m = c/2;
		ans= (b*a)*(c-2*m);
	}
	cout << ans;

}
