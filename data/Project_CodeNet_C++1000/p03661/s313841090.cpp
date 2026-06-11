#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
#define LL long long
#define INF 1ll<<60
using namespace std;
const int N=2e5+100;
const int mod=1e9+7;
LL arr[N],sum[N];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)cin>>arr[i];
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+arr[i];
		LL ans=INF;
		for(int i=1;i<n;i++){
			
			ans=min(ans,abs(sum[n]-sum[i]-sum[i]));
			
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
	
}