#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+10;
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	int maxx=0,minn=n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	} 
	if(maxx-minn>=2)return 0*printf("No\n");//不存在相差大于2的答案 
	bool flag=true;
	for(int i=1;i<n;i++)if(a[i]!=a[0])flag=false;
	if(flag==false)
	{
		int cnt = 0;
		for(int i=0;i<n;i++)if(a[i]==maxx-1)cnt++; 
		if(cnt<maxx&&2*(maxx-cnt)<=n-cnt)return 0*printf("Yes\n");
		return 0*printf("No\n");
	}else{
		if(a[0]==n-1)return 0*printf("Yes\n");
		else if(2*a[0]<=n)return 0*printf("Yes\n");
		else return 0*printf("No\n");
	}
}