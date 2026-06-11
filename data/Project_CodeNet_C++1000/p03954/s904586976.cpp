/*#include<bits/stdc++.h>         //暴力:(
using namespace std;  
int getint()
{
	char c;
	int ans=0,k=1;
	while(c=getchar(),c>'9' || c<'0') if(c=='-') k=-1;
	while(ans=ans*10+c-'0',c=getchar(),c>='0' && c<='9');
	return ans*k;
}
const int N=2e6+5;
int a[N][2];
int n;
int work(int x,int y,int z)
{
	int t;
	if(x>y) t=x,x=y,y=t;
	if(y>z) t=y,y=z,z=t;
	return x>y?x:y; 
}
int main()
{
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	scanf("%d",&n);
	int l=1,r=n*2-1;
	bool t=0,s;
	for(int i=1;i<=r;i++) cin>>a[i][t];
	for(int i=1;i<n;i++){
		s=!t;
		for(int j=l+i;j<=r-i;j++)
			a[j][s]=work(a[j-1][t],a[j][t],a[j+1][t]);
		t=!t;
	}
	cout<<a[n][s]<<endl;
}*/
#include<bits/stdc++.h>
using namespace std;
int getint()
{
	char c;
	int ans=0,k=1;
	while(c=getchar(),c>'9' || c<'0') if(c=='-') k=-1;
	while(ans=ans*10+c-'0',c=getchar(),c>='0' && c<='9');
	return ans*k;
}
const int N=2e6+5;
int n;
int a[N];
inline bool check(int k){
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))return 1;
    if((a[n-1]> k&&a[n]> k)||(a[n]> k&&a[n+1]> k))return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))return 1;
        if((a[n+i]> k&&a[n+i+1]> k)||(a[n-i]> k&&a[n-i-1]> k))return 0;
    }
    return a[1]<=k;
}
int main()
{
	scanf("%d",&n);
	int left=0,right=(n<<1)-1;
	for(int i=1;i<=right;i++) a[i]=getint();
	int mid;
	while(left<=right){
		mid=left+right>>1;
		if(check(mid)) right=mid-1;
		else left=mid+1;
	}
	printf("%d\n",left);
	
}