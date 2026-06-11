#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#define FAST ios::sync_with_stdio(false)
#define lowbit(x) x&(-x)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 5;
using namespace std;

priority_queue <ll, vector<ll>, greater<ll> > q1;//小的在前
priority_queue <ll> q2;//大的在前

ll a[maxn * 3];
ll l[maxn * 3], r[maxn * 3];//维护l最大,r最小

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= 3 * n; i++){
		scanf("%lld", &a[i]);
	}
	ll sum = 0;
	for(int i = 1; i <= 3 * n; i++){
		q1.push(a[i]);
		sum += a[i], l[i] = sum;
		if(q1.size() == n + 1){
			sum -= q1.top();
			q1.pop();
			l[i] = sum;
		}
	}
//---------------------------------------
	sum = 0;
	for(int i = 3 * n; i >= 1; i--){
		q2.push(a[i]);
		sum += a[i], r[i] = sum;
		if(q2.size() == n + 1){
			sum -= q2.top();
			q2.pop();
			r[i] = sum;
		}
	}
	ll ans = -1e15;
	for(int i = n; i <= 2 * n; i++){
		ans = max(ans, l[i] - r[i+1]);//left - right
	}
	printf("%lld\n", ans);
	return 0;
}