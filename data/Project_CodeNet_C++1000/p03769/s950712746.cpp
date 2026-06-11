#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<ctime>

using namespace std;

typedef long long LL;
const int MX=211;
const LL A[65]={0,0,0,1,2,4,7,11,18,29,47,76,116,188,299,457,738,1116,1898,2863,4580,7192,11266,17450,29302,43417,70260,108168,177299,271977,424553,688860,1067143,1727627,2628546,4494749,6533606,10396103,17042248,24940788,41151771,62502284,101045962,163624265,248705141,410323314,669284262,1032224761,1596203570LL,2482015025LL,3945430889LL,6206382434LL,10347315646LL,15153735045LL,23518168549LL,37249419965LL,58532880409LL,96540747097LL,155889322842LL,236068838564LL,364188525731LL,598004044095LL,927656514301LL,1451223365341LL};
LL dp[MX][MX],S[MX][MX];
LL cal1(int s[],int t[],int ls,int lt){
	for(int i=0;i<ls;i++)dp[i][0]=(s[i]==t[0]),S[i][0]=dp[i][0];
	for(int i=1;i<ls;i++)S[i][0]+=S[i-1][0];
	for(int i=1;i<lt;i++)S[0][i]=S[0][i-1];
	for(int j=1;j<lt;j++)
		for(int i=1;i<ls;i++)
			dp[i][j]=(s[i]==t[j]?S[i-1][j-1]:0),
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+dp[i][j];
	return S[ls-1][lt-1];
}
LL cal(int s[],int l){
	LL ans=0LL;
	for(int i=1;i<l;i++)ans+=cal1(s,s+i,i,l-i);
	return ans;
}
int ANS[MX],L;
void wk(LL n,int alp){
	if(!n)return;
	int len=upper_bound(A,A+63,n)-A-1;
	static int ans[MX];
	LL ansv=0;
	for(int i=1;i<=300;i++){
		static int s[MX];
		for(int j=0;j<len;j++)s[j]=rand()%3+alp;
		LL t=cal(s,len);
		if(t<=n&&t>ansv){
			ansv=t;
			memcpy(ans,s,sizeof(int)*len);
		}
	}
	memcpy(ANS+L,ans,sizeof(int)*len);L+=len;
	//for(int i=0;i<len;i++)printf("%d ",ans[i]);
	wk(n-ansv,alp+3);
}
int main(){
	//freopen("tbl.out","w",stdout);
	srand(time(0));
	LL n;scanf("%lld",&n);
	wk(n,1);
	printf("%d\n",L);
	for(int i=0;i<L;i++)printf("%d ",ANS[i]);
	puts("");
	/*
	for(int n=1;n<=63;n++){
		double sum=0.0;
		for(int i=1;i<=1000;i++){
			static int s[MX];
			for(int j=0;j<n;j++)s[j]=rand()%3+1;
			//printf("%lld ",cal(s,n));
			sum+=cal(s,n);
		}
		sum/=1000;
		printf("%.0f,",sum);
	}
	*/
	//while(1);
	return 0;
}
