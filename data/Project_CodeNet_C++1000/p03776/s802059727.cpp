#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

long long fact(int x){
	if(x==0)return 1ll;
	return fact(x-1)*x;
}
long long comb(int x, int y){
	long long ret=1ll;
	for(int i = 1;i <= y;i ++){
		ret=ret*(x+1-i)/i;
	}
	return ret;
}
int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	vector <long long> v(n);
	for(auto&i:v)
		scanf("%lld", &i);
	sort(v.begin(), v.end());
	long double sum=0.0l;
	for(int i = n;i > n-a;i --){
		sum+=v[i-1];
	}
	printf("%.10Lf\n", sum/a);
	if(v[n-a]!=v[n-1]){//must pick a
		printf("%lld\n", comb(count(v.begin(), v.end(), v[n-a]),count(v.begin()+(n-a), v.end(), v[n-a])));
	}else{//can pick any number
		long long ans=0ll;
		for(int i = a;i <= b;i ++){
			if(v[n-i]!=v[n-1])
				break;
			ans+=comb(count(v.begin(), v.end(), v.back()), i);
		}
		printf("%lld\n", ans);
	}
}