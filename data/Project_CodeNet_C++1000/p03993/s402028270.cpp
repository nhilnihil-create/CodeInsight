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
	int N;
	cin >> N;
	int arr[N];
	REP(i, 0, N) cin >> arr[i];
	
	int ans= 0;
	REP(i, 0, N){
		if(arr[i] > i && arr[arr[i]-1]-1 == i) ++ans;
	}
	cout << ans; 

}
