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
	int N;
	cin >> N;
	int arr[3*N] = {0};
	REP(i, 0, 3*N) cin >> arr[i];
	sort(arr, arr+3*N);
	
	ll ans = 0, index = 0;
	REP(i, N, 3*N){
		if(index % 2 == 0) ans+= arr[i];
		++index;
	}
	cout << ans;
}
