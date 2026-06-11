#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long sn = n*(n+1)/2;
	long long arr[n];
	long long sum = 0;
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum % sn != 0){
		cout << "NO" <<endl;
		return 0;
	}
	long long ans = 1;
	long long cnt = sum/sn;
	long long awal = cnt;
	for(long long i = 0; i < n; i++){
		long long z = awal;
		while(arr[i]+z != arr[(i+1)%n]){
			cnt--;
			z-=n;
			if(arr[i]+z <  arr[(i+1)%n]){
				ans = 0;
				break;
			}
		}
		if(ans == 0)break;
	}
	if(cnt != 0 || ans == 0)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
	
}