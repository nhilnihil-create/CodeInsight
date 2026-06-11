#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[200005],s[200005],x[200005];

bool check(){
	int N=2*n-1;
	int l=n,r=n,res=a[n];
	a[0]=a[1],a[N+1]=a[N];
	for(; l>=1&&a[l-1]!=a[l]&&a[r+1]!=a[r]; --l,++r) res^=1;
	return res;
}

int main()
{
	cin >> n;
	for(int i=1; i<=2*n-1; i++)	scanf("%d",&s[i]),x[i]=s[i];
	sort(s+1,s+n*2);
	int l=1,r=2*n-1;
	while(l<=r){
		int	mid=(l+r)>>1;
		for(int i=1; i<=2*n-1; i++) a[i]=x[i]>s[mid];
		if(!check()) r=mid-1,ans=mid;
		else l=mid+1;
	//	cout << mid<<endl;
	}
	printf("%d",s[ans]);
	return 0;
}