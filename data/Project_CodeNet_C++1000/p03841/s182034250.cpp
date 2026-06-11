#include<bits/stdc++.h>
using namespace std;

const int maxn=5e2+10;
int n,a[maxn*maxn],l[maxn],r[maxn];
pair<int,int> x[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x[i].first;
		x[i].second=i;
		a[x[i].first]=i;
		l[i]=i-1;
		r[i]=n-i;
	}
	sort(x+1,x+n+1);
	for(int i=1,j=1;i<=n*n;++i){
		while(j<=n&&!l[x[j].second])
			++j;
		if(a[i]){
			if(j<=n&&a[i]==x[j].second){
				puts("No");
				return 0;
			}
		}
		else{
			if(j<=n){
				a[i]=x[j].second;
				--l[x[j].second];
			}
		}
	}
	for(int i=n*n,j=n;i;--i){
		while(j&&!r[x[j].second])
			--j;
		if(a[i]){
			if(j&&a[i]==x[j].second){
				puts("No");
				return 0;
			}
		}
		else{
			if(j){
				a[i]=x[j].second;
				--r[x[j].second];
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)
		printf("%d ",a[i]);
	puts("");
	return 0;
}