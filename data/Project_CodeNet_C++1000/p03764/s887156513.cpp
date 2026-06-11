#include <iostream>
#include <cmath>
#define K 1000000007

using namespace std;
int main(){
	int n,m,i;
	cin >> n >> m;
	long long x[n],y[m],a=0,b=0;
	
	for(i=0;i<n;i++){
		cin >> x[i];
		x[i] = (x[i]+K)%K;
	}
	
	for(i=0;i<m;i++){
		cin >> y[i];
		y[i] = (y[i]+K)%K;
	}
	for(i=0;i<n;i++){
		a = a+(2*(i+1)-n-1+K)%K*x[i];
		a = (a+K)%K;
	}
	for(i=0;i<m;i++){
		b = b+(2*(i+1)-m-1+K)%K*y[i];
		b = (b+K)%K;
	}
	
	long long ans = a%K*b%K;
	
	cout << ans%K << endl;
}