#include <iostream>
#define llint long long
#define inf 1000000000000000000

using namespace std;

llint n, m;
llint a[100005];
llint sum[100005];

llint dif(llint a, llint b)
{
	llint ret = a - b;
	if(ret < 0) ret += m;
	return ret;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	
	llint ans = inf, step = 0, loop = 0, all = 0;
	for(int i = 0; i < n-1; i++){
		sum[a[i+1]] += dif(a[i+1], a[i]);
		all += dif(a[i+1], a[i]);
		if(a[i+1] < a[i]){
			step += dif(0, a[i])-1;
			loop++;
		}
	}
	ans = all - step;
	
	for(int i = 1; i < m; i++){
		step += loop;
		if(i >= a[n-1]+2) step--;
		if(i >= a[0]+2) step++;
		step -= sum[i-1];
		ans = min(ans, all - step);
	}
	
	cout << ans << endl;
	return 0;
}