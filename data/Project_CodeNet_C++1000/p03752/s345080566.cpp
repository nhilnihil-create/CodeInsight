#include <stdio.h>
int n,k;
long long a[20];
long long b[20];
int cnt;
long long min(long long a, long long b){
	return a<b?a:b;
}
long long f(int x){
	long long res = 1e9;
	res = res * res;
	if(x==n+1){
		if(cnt < k){
			return res;
		}
		long long ans = 0;
		long long max_height = a[1];
		int cur_cnt = 1;
		if(b[cur_cnt]==1) cur_cnt++;
		for(int i=2;i<=n;i++){
			if(cur_cnt > cnt) break;
			if(i==b[cur_cnt]){
				if(max_height >= a[b[cur_cnt]]){
					ans+=max_height-a[b[cur_cnt]]+1;
					max_height++;
				} else {
					max_height = a[b[cur_cnt]];
				}
				cur_cnt++;
			} else {
				if(max_height < a[i]){
					max_height = a[i];
				}
			}
		}
		return ans;
	}
	res = min(res,f(x+1));
	b[++cnt] = x;
	res = min(res,f(x+1));
	cnt--;
	return res;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",f(1));
}