#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int cnt[9]={0};
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a<400){
			cnt[1]++;
		}else if(a<800){
			cnt[2]++;
		}else if(a<1200){
			cnt[3]++;
		}else if(a<1600){
			cnt[4]++;
		}else if(a<2000){
			cnt[5]++;
		}else if(a<2400){
			cnt[6]++;
		}else if(a<2800){
			cnt[7]++;
		}else if(a<3200){
			cnt[8]++;
		}else{
			cnt[0]++;
		}
	}
	int how=0;
	for(int i=1;i<9;i++){
		if(cnt[i])how++;
	}
	cout<<max(how,1)<<' '<<how+cnt[0];
	return 0;
}