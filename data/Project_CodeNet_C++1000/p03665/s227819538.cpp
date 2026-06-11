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

ll arr[5001];

void sum_arr(int pos, long long a[], int s, ll sum){
	if(pos == s) return;
	else{
		sum_arr(pos+1, a, s, sum);
		if(sum+a[pos] <= 5000){
			++arr[sum+ a[pos]];
			sum_arr(pos+1, a, s, sum + a[pos]);
		}
	}
}

int main() {
	ll n, p, ans=0, l=0, s=0, tmp;
	cin >> n >> p;
	REP(i, 0, n){
		cin >> tmp;
		if(tmp % 2 == 0) ++s;
		else ++l;
	}
	
	if(p == 0){
		if(l > 0) ans = pow(2, n-1);
		else ans = pow(2, n);
	}
	else{
		if(l > 0 ) ans = pow(2, n-1);
		else ans = 0;
	}
	cout << ans;
}
