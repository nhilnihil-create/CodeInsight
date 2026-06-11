#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 1000000
#define ll long long 
using namespace std;

priority_queue<ll, vector<ll>, greater<ll> > front;
priority_queue<ll> back; 
ll a[MAXN], l[MAXN], r[MAXN];//前l[i]包括l[i]本身N项和的最大值 
int main() {
	ll n, sumf = 0, sumb = 0, ans = -1e18;
	scanf("%lld", &n);
	for(int i = 1; i <= 3*n; i++) {
		scanf("%lld", &a[i]);		
		if(i <= n) sumf += a[i], front.push(a[i]);
		if(i > 2*n) sumb += a[i], back.push(a[i]);
	}
	l[n] = sumf, r[2*n] = sumb;
	for(int i = n+1; i <= 2*n; i++) {
		if(a[i] > front.top()) {
			sumf = sumf - front.top() + a[i];
			front.pop();
			front.push(a[i]);
		}
		l[i] = sumf;
	} 
	
	for(int i = 2*n-1; i >= n; i--) {	
		if(a[i+1] < back.top()) {
			sumb = sumb - back.top() + a[i+1];
			back.pop();
			back.push(a[i+1]);
		}
		r[i] = sumb;
	}
	for(int i = n; i <= 2*n; i++) 
		ans = max(ans, l[i]-r[i]);
	
	printf("%lld\n", ans);
	
	return 0;
}