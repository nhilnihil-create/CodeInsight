#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	unsigned long long  Q,H,S,D,N;
	cin >> Q >> H >> S >> D >> N;
	
	if(4*Q < S) S = 4*Q;
	if(2*H < S) S = 2*H;
	
	if(2*S > D) cout << (N%2==1?S:0) + (N-(N%2==1?1:0))/2 * D;
	else cout << S * N;

}
