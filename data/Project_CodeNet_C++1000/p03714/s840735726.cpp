#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
 
const long long MAX = -1e18;
const long long MAXN = 3e5 + 5;
long long dp_f[MAXN],dp_e[MAXN],a[MAXN];
 
priority_queue<long long , vector<long long> , greater<long long> > que;
priority_queue<long long>pque;
 
void Slove_f(int n){
	long long sum_f = 0;
	for(int i = 1;i <= 3 * n;i++){
		que.push(a[i]);
		sum_f += a[i];
		dp_f[i] = sum_f;
		if(que.size() > n){
			sum_f -= que.top();
			que.pop();
			dp_f[i] = sum_f;
		}
	}
 
}
 
void Slove_e(int n){
	long long sum_e = 0;
	for(int i = 3 * n;i >= 1;i--){
		pque.push(a[i]);
		sum_e += a[i];
		dp_e[i] = sum_e;
		if(pque.size() > n){
			sum_e -= pque.top();
			pque.pop();
			dp_e[i] = sum_e;
		}
	}
 
}
 
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= 3 * n;i++) scanf("%lld",&a[i]);
 
	Slove_f(n);	
	Slove_e(n);
 
	long long ans = MAX;
	for(int i = n;i <= 2 * n;i++){
		ans = max(ans,dp_f[i] - dp_e[i + 1]);
	}
	printf("%lld",ans);
}