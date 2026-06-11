#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

int n;
long long ans;
long long v[MAXN];

int main(){
	scanf("%d", &n);
	//n = 300000;
	stack<long long> stk;
	for(int i = 1; i <= n; i++)
		//v[i] = 100000000;
		scanf("%lld", &v[i]);
	for(int i = 1; i <= n + 1; i++){
		while(!stk.empty() && v[stk.top()] >= v[i]){
			long long height = v[stk.top()];
			int idx = stk.top();
			stk.pop();
			int right = stk.empty() ? 0: stk.top(), left = i;
			ans += v[idx] * (idx - right) * (left - idx);
			//printf("v[%d] = %lld\nleft = %d, right = %d\nsum = %lld\n", idx, v[idx], right, left, v[idx] * (idx - right) * (left - idx));
		}
		stk.push(i);
	}
	printf("%lld\n", ans);
}