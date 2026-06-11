#include<cstdio>
#include<ctime>

#define gec     getchar
#define FILE(F) freopen(F".in","r",stdin),freopen(F".out","w",stdout)
#define RunTime fprintf(stderr,"Running Time:%.5lfs\n",1.*clock()/1e6)

typedef long long ll;
typedef long double lb;
template<typename T>void umin(T &x,T y){if(x>y)x=y;}
template<typename T> T min(T x,T y){return x<y?x:y;}
template<typename T>void umax(T &x,T y){if(x<y)x=y;}
template<typename T> T max(T x,T y){return x>y?x:y;}
template<typename T>
inline void read(T &x)
{
	x=0;bool f=0; char c=gec();
	for(;c<'0'||c>'9';c=gec())f=(c=='-');
	for(;c>='0'&&c<='9';c=gec())x=x*10+c-'0';
	x=f?-x:x;
}

namespace DEBUG{
inline void fpr(char *c){fprintf(stderr,"%s\n",c);}
inline void fpr(int    x,char *c){fprintf(stderr,"[ %s ] : = %d   \n",c,x);}
inline void fpr(ll     x,char *c){fprintf(stderr,"[ %s ] : = %lld \n",c,x);}
inline void fpr(double x,char *c){fprintf(stderr,"[ %s ] : = %.5lf\n",c,x);}
inline void fpr(lb     x,char *c){fprintf(stderr,"[ %s ] : = %.5Lf\n",c,x);} 
}using namespace DEBUG;

char ch[10];

ll NOW=999991515;
int sa[20],sb[20];
bool cmp(ll a,ll b)
{
	sa[0]=sb[0]=0;
	while(a)sa[++sa[0]]=a%10,a/=10;
	while(b)sb[++sb[0]]=b%10,b/=10;
	while(sa[sa[0]]==sb[sb[0]]&&sa[0]&&sb[0])sa[0]--,sb[0]--;
	fpr(sa[0],"sa");
	fpr(sb[0],"sb");
	if(!sa[0]||!sb[0])return sa[0]<sb[0];
	return sa[sa[0]]<sb[sb[0]];
}

bool Check(ll x)
{
	return (x<NOW)==cmp(x,NOW);
}

bool ASK(ll x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",ch);
	return ch[0]=='Y';
	/*fpr(x,"x");
	fpr(Check(x),"bf");
	return Check(x);*/
}

ll p9[11],p10[12];
int leng,Ans;
void Bit()
{
	int l=1,r=10,mid,id=1;p10[0]=1;
	for(int i=1;i<=10;i++)p9[i]=p9[i-1]*10+9,p10[i]=p10[i-1]*10;
	while(l<=r) if(ASK(p9[mid=(l+r)>>1]))r=mid-1,id=mid;else l=mid+1;
	leng=id;
	l=1,r=10,id=1;
	while(l<=r) if(ASK(p10[mid=(l+r)>>1]))l=mid+1;else r=mid-1,id=mid;
	umax(leng,id);
}

void Get_Last()
{
	int Last=0;
	for(int i=9;i>=(Ans==0);i--)
	if(ASK(1ll*(Ans*10+i)*10))Last=i;else break;
	Ans=Ans*10+Last;
	printf("! %d\n",Ans);
}

void ByBit()
{
	if(leng==10){printf("! %d\n",1000000000);return ;}
	int l=1,r=9,mid;
	if(leng==1)Get_Last();
	else
	{
		while(l<=r) if( ASK( 1ll*(mid=(l+r)>>1)) )l=mid+1,Ans=mid;else r=mid-1;
		for(int i=2;i<leng;i++)
		{
			fpr(Ans,"Ans");
			int l=0,r=9,mid,x;
			while(l<=r)
			{
				if(ASK( (1ll*Ans*10+(mid=(l+r)>>1))) )l=mid+1,x=mid;else r=mid-1;
			}
			Ans=Ans*10+x;
		}
		Get_Last();
	}
}

int main()
{
	Bit();
	ByBit();
	return 0;
}	