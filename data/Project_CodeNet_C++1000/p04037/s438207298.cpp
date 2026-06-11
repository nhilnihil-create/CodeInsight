#include <bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int n,a[maxn],ans;
bool cmp(int a,int b){return a>b;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i+1>a[i+1]){
			for(int j=i+1;a[j]==i;j++)
				ans^=1;
			ans|=(a[i]-i)&1;
			if(ans&1) printf("First\n");
			else printf("Second\n");
			return 0;
		}
	}
}