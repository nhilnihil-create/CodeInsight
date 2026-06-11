#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1 << 30;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll n, x;

int main(void){
	cin>>n>>x;

	cout<< 3 * (n - gcd(n, x)) <<endl;
	
	return 0;
}