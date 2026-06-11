#include <iostream>

int min(int x,int y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}

int main(){
	int n;
	int t[100002],a[100002],da[100002];
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::cin >> t[i];
	}
	for(int i=0;i<n;i++){
		std::cin >> a[i];
		da[i]=-1;
	}
	da[0]=t[0];
	for(int i=1;i<n;i++){
		if(t[i]!=t[i-1]){
			da[i]=t[i];
		}
	}
	long long ans=1;
	if(da[n-1]==a[n-1]||da[n-1]==-1){
		da[n-1]=a[n-1];
	}else{
		ans=0;
	}
	for(int i=n-2;i>-1;i--){
		if(a[i]!=a[i+1]){
			if(da[i]==-1||da[i]==a[i]){
				da[i]=a[i];
			}else{
				ans=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(da[i]==-1){
			ans=(long long)ans*min(a[i],t[i]);
			ans%=1000000007;
		}else{
			if(da[i]>min(a[i],t[i])){
				ans=0;
			}
		}
	}
	std::cout << ans << std::endl;
}