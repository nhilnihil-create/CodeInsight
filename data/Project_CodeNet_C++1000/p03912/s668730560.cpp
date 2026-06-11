#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n,m,tmp,ans,ichi;
	ans =0;
	ichi=0;
	cin >> n >> m;
	int x[200001]={};
	int y[200001]={};
	for(int i=0;i<n;i++){
		cin >> tmp;
		y[tmp%m]+=1;
		x[tmp]+=1;
	}
	if(m%2==1){
		ans += y[0]/2;
		for(int i=1;i<=(m/2);i++){
			ans+=min(y[i],y[m-i]);
			if(y[i]>y[m-i]){
				for(int j=0;j<(n/m+1);j++){
					if(x[i+m*j]>=2){
						ichi+=x[i+m*j]/2;
					}
				}
				if(2*ichi>=(y[i]-y[m-i])){
					ans += (y[i]-y[m-i])/2;
				}else{
					ans +=ichi;
				}
				ichi=0;
			}else if(y[i]<y[m-i]){
				for(int j=0;j<(n/m+1);j++){
					if(x[m-i+m*j]>=2){
						ichi+=x[m-i+m*j]/2;
					}
				}
				if(2*ichi>=(y[m-i]-y[i])){
					ans += (y[m-i]-y[i])/2;
				}else{
					ans +=ichi;
				}
				ichi=0;
			}
		}
	}else{
		ans += y[0]/2;
		ans += y[m/2]/2;
		for(int i=1;i<=(m/2-1);i++){
			ans+=min(y[i],y[m-i]);
			if(y[i]>y[m-i]){
				for(int j=0;j<(n/m+1);j++){
					if(x[i+m*j]>=2){
						ichi+=x[i+m*j]/2;
					}
				}
				if(2*ichi>=(y[i]-y[m-i])){
					ans += (y[i]-y[m-i])/2;
				}else{
					ans +=ichi;
				}
				ichi=0;
			}else if(y[i]<y[m-i]){
				for(int j=0;j<(n/m+1);j++){
					if(x[m-i+m*j]>=2){
						ichi+=x[m-i+m*j]/2;
					}
				}
				if(2*ichi>=(y[m-i]-y[i])){
					ans += (y[m-i]-y[i])/2;
				}else{
					ans +=ichi;
				}
				ichi=0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}