//problem:AT2273
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/* --------------- fast io --------------- */ // begin
namespace Fread{
const int MAXN=1<<20;
char buf[MAXN],*S,*T;
inline char getchar(){
	if(S==T){
		T=(S=buf)+fread(buf,1,MAXN,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
}//namespace Fread
namespace Fwrite{
const int MAXN=1<<20;
char buf[MAXN],*S=buf,*T=buf+MAXN;
inline void flush(){
	fwrite(buf,1,S-buf,stdout);
	S=buf;
}
inline void putchar(char c){
	*S++=c;
	if (S==T)flush();
}
struct _{
	~_(){flush();}
}__;
}//namespace Fwrite

#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif

template<typename T>inline void read(T& x){
	x=0;int f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	x*=f;
}
template<typename T>inline void write(T x,bool _enter=0,bool _space=0){
	if (!x)putchar('0');else{
		if(x<0)putchar('-'),x=-x;
		static char dig[41];
		int top=0;
		while(x)dig[++top]=(x%10)+'0',x/=10;
		while(top)putchar(dig[top--]);
	}
	if(_enter)putchar('\n');
	if(_space)putchar(' ');
}

namespace Fastio{
struct reader{
	template<typename T>reader& operator>>(T& x){::read(x);return *this;}
	reader& operator>>(char& c){
		c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		return *this;
	}
	reader& operator>>(char* str){
		int len=0;
		char c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		while(c!='\n'&&c!=' ')str[len++]=c,c=getchar();
		str[len]='\0';
		return *this;
	}
}cin;
const char endl='\n';
struct writer{
	template<typename T>writer& operator<<(T x){::write(x,0,0);return *this;}
	writer& operator<<(char c){putchar(c);return *this;}
	writer& operator<<(const char* str){
		int cur=0;
		while(str[cur])putchar(str[cur++]);
		return *this;
	}
}cout;
}//namespace Fastio
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
/* --------------- fast io --------------- */ // end

const int MAXN=1e5;
const ll INF=1e18;
inline void cmax(ll& x,ll y){x=(x>y?x:y);}

int n,a[MAXN+5],op[MAXN+5];
ll dp[MAXN+5][3];

int main() {
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i!=n){
			char c;cin>>c;
			op[i]=(c=='+'?1:-1);
		}
	}
	op[0]=1;
	dp[0][1]=dp[0][2]=-INF;
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i][1]=dp[i][2]=-INF;
		for(int j=0;j<=2;++j)if(dp[i-1][j]!=-INF){
			cmax(dp[i][j],dp[i-1][j]+((j&1)?-1:1)*op[i-1]*a[i]);
			if(op[i-1]==-1&&j!=2){
				cmax(dp[i][j+1],dp[i-1][j]+(j==0?-1:1)*a[i]);
			}
			if(j!=0){
				cmax(dp[i][j-1],dp[i-1][j]+((j&1)?-1:1)*op[i-1]*a[i]);
			}
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}