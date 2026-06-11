// È¥°É£¡Æ¤¿¨Çð! °ÑAC´ø»ØÀ´£¡
//      ¤Ø¡¡¡¡¡¡¡¡¡¡£¯|
// ¡¡¡¡/£Ü7¡¡¡¡¡¡ ¡Ï£ß/
// ¡¡ /¡¡©¦¡¡¡¡ £¯¡¡£¯								AC		AC		AC		AC
//    ©¦¡¡Z £ß,£¼¡¡£¯¡¡¡¡ /`©c						AC		AC		AC		AC
//    ©¦¡¡¡¡¡¡¡¡¡¡©c¡¡¡¡ /¡¡¡¡¡µ					AC		AC		AC		AC
// ¡¡Y¡¡¡¡¡¡¡¡¡¡`¡¡ /¡¡¡¡/  /						AC		AC		AC		AC
// ¡¡Øé¡ñ¡¡.¡¡¡ñ¡¡¡¡¡´¡¡/¡¡/						AC		AC		AC		AC
// ¡¡()¡¡ ¤Ø¡¡¡¡¡¡¡¡|¡¡£Ü¡´							AC		AC		AC		AC
// ¡¡¡¡>- ._¡¡ ¥£¡¡ ©¦ £¯£¯							AC		AC		AC		AC
// ¡¡ / ¤Ø¡¡¡¡ /¡¡/£¼| £Ü£Ü							AC		AC		AC		AC
// ¡¡ ©c_/¡¡¡¡(_£¯¡¡ ©¦£¯£¯							AC		AC		AC		AC
// ¡¡¡¡ 7¡¡¡¡¡¡¡¡¡¡¡¡¡¡|£¯							AC		AC		AC		AC
// ¡¡¡¡ £¾¨Dr£þ£þ`-¨D£ß/							AC		AC		AC		AC
//**************************************Accepted*****************************************//

#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define Pig (OO)

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

const int Days[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};

inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}

typedef long long ll;

const int MAX_Types=40;
const int MAX_a=10;
const int MAX_b=10;
int n,ma,mb;
int a[MAX_Types+10],b[MAX_Types+10],c[MAX_Types+10];
const int MAX_tot_a=MAX_Types*MAX_a;
const int MAX_tot_b=MAX_Types*MAX_b;
int dp[MAX_Types+10][MAX_tot_a+10][MAX_tot_b+10];
const int INF=1000000007;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	cin>>n>>ma>>mb;
	
	for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
	
	for(int i=0;i<=MAX_Types;i++)for(int j=0;j<=MAX_tot_a;j++)for(int k=0;k<=MAX_tot_b;k++)dp[i][j][k]=INF;
	
	dp[0][0][0]=0;
	
	for(int i=0;i<n;i++)for(int tot_a=0;tot_a<=MAX_tot_a;tot_a++)for(int tot_b=0;tot_b<=MAX_tot_b;tot_b++)if(dp[i][tot_a][tot_b]!=INF)
	{
		dp[i+1][tot_a][tot_b]=min(dp[i][tot_a][tot_b],dp[i+1][tot_a][tot_b]);
		dp[i+1][tot_a+a[i]][tot_b+b[i]]=min(dp[i+1][tot_a+a[i]][tot_b+b[i]],dp[i][tot_a][tot_b]+c[i]);
	}
	
	int ans=INF;
	
	for(int i=1;i<=MAX_tot_a;i++)for(int j=1;j<=MAX_tot_b;j++)ans=(i*mb==j*ma ? min(ans,dp[n][i][j]) : ans);
	
	cout<<(ans==INF ? -1 : ans);
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}

/*  GOD BLESS  */
