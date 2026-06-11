#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc()) if(ch=='-') positive=0;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(ll x){
	if(x<0){
		x=-x;putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=10;
char s[N];
ll NN=123;
poly a,b;
void init(ll x){
	b.clear();
	while(x){
		b.pb(x%10);
		x/=10;
	}
	reverse(b.begin(),b.end());
}
bool check(ll x){
	init(x);
	int n=a.size(),m=b.size();
	if(x<=NN){
		For(i,0,min(n,m)-1){
			if(b[i]<a[i]) return 1;
			if(a[i]<b[i]) return 0;
		}
		return m<=n;
	}
	For(i,0,min(n,m)-1){
		if(b[i]<a[i]) return 0;
		if(b[i]>a[i]) return 1;
	}
	return m>n;
}
int cnt;
void query(ll x){
	// cnt++;
	// init(x);
	printf("? %lld\n",x);
	// if(check(x)) s[0]='Y';
	// else s[0]='N';
	// cout<<s[0]<<endl;
	fflush(stdout);scanf("%s",s);
}
int main(){
	// ll t=NN;
	// while(t) a.pb(t%10),t/=10;
	// reverse(a.begin(),a.end());
	ll alb=1;int pos=10;
	For(i,1,10){
		alb*=10;query(alb);
		if(s[0]=='N'){
			pos=i;break;
		}
	}
	ll ssw=0;
	For(i,1,pos){
		int ksg=-1;
		query(ssw*10+9);
		if(s[0]=='N'){
			int l=(i==1),r=8,mid,pos=9;
			while(l<=r){
				mid=l+r>>1;query(ssw*10+mid);
				if(s[0]=='N') r=(pos=mid)-1;
				else l=mid+1;
			}
			ksg=pos-1;
		}
		if(ksg==-1){
			if(i==1){
				query(1e9);
				if(s[0]=='Y'){
					ssw=1;break;
				}
				if(pos>=2) ssw=ssw*10+9;
				else{
					For(j,1,9){
						query(j*10);
						if(s[0]=='Y'){
							ssw=j;break;
						}
					}
					break;
				}
			}else{
				ll mjn=ssw;
				while(mjn<=1e9) mjn*=10;
				query(mjn);
				if(s[0]=='Y'){
					ssw*=10;break;
				}
				if(i==pos){
					For(j,1,9){
						query(ssw*100+j*10);
						if(s[0]=='Y'){
							ssw=ssw*10+j;break;
						}
					}
					break;
				}else ssw=ssw*10+9;
			}
		}else ssw=ssw*10+ksg;
	}
	// cout<<cnt<<endl;
	printf("! %lld",ssw);
}
