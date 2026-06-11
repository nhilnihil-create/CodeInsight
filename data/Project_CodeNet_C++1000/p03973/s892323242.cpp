// In the name of god
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
using ll = long long;
const ll N = 1e5 + 5, inf = 4e18;
ll n, k = 2, a[N], ans;  
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n ;
	for(ll i = 0; i < n; i++){
		cin >> a[i] ;
		if(i == 0){
			ans += a[i] - 1;
			continue;
		} 
		if(a[i] < k)continue;
		if(a[i] == k)
			k ++;
		else{
			ll z = (a[i] - 1) / k;
			ans += z; 
			continue;
		}
	}
	cout << ans << endl;
}
