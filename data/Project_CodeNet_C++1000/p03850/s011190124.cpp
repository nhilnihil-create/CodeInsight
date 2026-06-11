#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
int a[N];
int op[N];
int n;
ll dp[N][3];
string s;
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	scanf("%d",&n);getchar();
	getline(cin,s);
	int len=s.length(),t=0,p1=0,p2=0;  
	for(int i=0;i<len;i++){
		if(s[i]==' '){
			if(t)a[++p1]=t;
			t=0;continue;
		}else if(s[i]>='0'&&s[i]<='9')t=t*10+s[i]-'0';
		else{
			if(s[i]=='-')op[++p2]=-1;else op[++p2]=1;
		}
	}
	a[++p1]=t;
	dp[1][0]=a[1],dp[1][2]=dp[1][1]=-1e18;
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i][1]=dp[i][2]=-1e18;
		int f=(op[i-1]==-1);
		for(int j=0;j<3;j++){
			int t=j%2;
			t=t^f;
			int temp=a[i];
			if(t)temp=-temp;
			if(f&&j<2)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+temp);
			for(int k=0;k<=j;k++)dp[i][k]=max(dp[i][k],dp[i-1][j]+temp);
		}
	}
	//for(int i=1;i<=p1;i++)cout<<a[i]<<" ";puts("");
	//for(int i=1;i<=p2;i++)cout<<op[i]<<" ";puts("");
	printf("%lld\n",dp[n][0]);

	return 0;
}