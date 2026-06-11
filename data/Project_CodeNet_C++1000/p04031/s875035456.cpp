#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
int a[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=1e9;
	for(int i=-100;i<=100;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=(i-a[j])*(i-a[j]);
		}
		ans=min(ans,sum);
	} 
	cout<<ans;
	return 0;
}