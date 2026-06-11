#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a[200008], sum, ans;

int main(){
	cin >> n;
	sum = 0;
	for(ll i = 1; i <= n; i++){cin >> a[i]; sum += a[i];}
	for(ll i = 1; i <= n; i++){a[i] += a[i-1];}
	
	ans = abs(sum-2*a[1]);
	for(ll i = 2; i <= n-1; i++){
		ans = min(abs(sum-2*a[i]), ans);
	}
	cout << ans << endl;
	return 0;
}