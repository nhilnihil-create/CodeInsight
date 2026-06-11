#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

string c="RYGB";

int main(void){
	int h,w,d,i,j,x,y;
	cin >> h >> w >> d;
	for(i=0; i<h; ++i){
		for(j=0; j<w; ++j){
			x = (i+j)/d;
			y = (500+i-j)/d;
			cout << c[(x%2)*2+y%2];
		}
		cout << endl;
	}
	return 0;
}
