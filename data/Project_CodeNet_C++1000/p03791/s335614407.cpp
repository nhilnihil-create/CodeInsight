#include<bits/stdc++.h>
using namespace std;

const int N=100005,P=1000000007;
int n,x[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",x+i);
	int ans=1;
	for(int i=0,j=0;i<n;++i){
		while(j<n&&x[j+1]>=2*(j-i)+1)++j;
		ans=1LL*ans*(j+(j<n&&x[j+1]>=2*(j-i))-i)%P;
	}
	printf("%d\n",ans);
}
