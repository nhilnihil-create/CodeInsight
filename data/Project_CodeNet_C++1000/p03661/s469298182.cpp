#include<iostream>
using namespace std;
int n;
int a[200000+5];
long long sum = 0;
long long sum1 = 0;
long long span = (2e5)*(1e9)+5;
int main(){
	scanf("%d",&n);
	for(int i = 1; i <=n;i++){
		scanf("%d",&a[i]);
		sum = sum + a[i];
	}
	for(int i = 1;i<n;i++){
		sum1 = sum1 + a[i];
		long long m = sum - 2*sum1;
		if(m<0){
			m = -m;
		}
		if(m<span){
			span = m;
		}
	}
	printf("%lld\n",span);
	return 0;
}