#include<bits/stdc++.h>
using namespace std;

#define INF (1LL<<60)

int a[20],b[20];

int main(){
	int n,k;	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];

	long long ans=INF;
	for(int i=0; i<(1<<n); i++){
		int b_cnt=0;
		int maxH=0;
		long long cost=0;
		for(int j=0;j<n;j++){
			b[j]=a[j];

			if((i>>j)&1){
				b_cnt++;
				if(maxH>=b[j]){
					++maxH;
					cost+=maxH-b[j];
					b[j]=maxH;
				}
			}
			maxH=max(maxH,b[j]);
		}
		if(b_cnt<k)continue;

		ans=min(ans,cost);

	}
	cout<<ans<<endl;

	return 0;
}
