#include<bits/stdc++.h>

#define pb push_back
#define S second
#define F first
typedef long long ll;

using namespace std;

const ll maxn = 5e5 + 10;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

ll n, p, a[maxn], ans, k;

int main(){

//	freopen("input.txt", "r", stdin);
	
	cin >> n;
	for(int i=0;i < n;i++){
		cin >> a[i];
	}
	p = 2;
	ans = a[0] - 1;
	for(int i=1;i < n;i++){
		ans += a[i] / p;
		if(!(a[i] % p)){
			ans--;
		}
		if(a[i] == p){
			p++;
		}
	}
	cout << ans << endl;

	return 0;
}