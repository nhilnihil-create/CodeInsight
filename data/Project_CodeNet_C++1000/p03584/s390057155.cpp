#include <iostream>

using namespace std;
long long ans,sum,a[100010],b[100010],n,k,l;
int main(){
	int i,j;
	cin >> n >> k;
	for(i=0;i<n;i++){
		cin >> a[i] >> b[i];
		if((k | a[i]) == k){
			ans += b[i];
		}
	}
	for(j=0;j<=30;j++){
		if(k & (1<<j)){
			l = (k - (1<<j))|((1<<j)-1);
			sum = 0;
			for(i=0;i<n;i++){
				if((l | a[i]) == l){
					sum += b[i];
				}
			}
			ans = max(ans,sum);
		}
	}
	cout << ans << endl;
}