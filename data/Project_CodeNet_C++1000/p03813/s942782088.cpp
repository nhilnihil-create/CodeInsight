#include<bits/stdc++.h>
#define ns "-1"
#define fs(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(ll i=x;i>=y;i+=z)
#define ll long long
#define ull unsigned long long
#define db double
#define ms(a,b) memset(a,b,sizeof(a))
#define sz(a) sizeof(a)
using namespace std;
const int rw[]={-1,0,1,0,-1,1,-1,1},cl[]={0,1,0,-1,-1,1,1,-1};
const int N=100001,inf=0x7f7f7f7f;
const db E=2.718281828459,pi=acos(-1.0),eps=0.0000000001;
inline bool xr(bool x,bool y){
	return x==y?0:1;
}
inline int read(){
	int date=0,w=1;char c=0;
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}
ull ksm(ull a,ull b){
    ull ans=1,base=a;
    while(b){
        if(b&1){
            ans*=base;
	    }
	    base*=base;
	    b>>=1;
	}
    return ans;
}
ll gcd(ll a,ll b){
    if(b) return gcd(b,a%b);
    return a;
}
bool prm(ll k){
	if(k<2) return 0;
	if(k==2||k==3||k==5) return 1;
	if(k%2==0||k%3==0||k%5==0) return 0;
	fs(i,7,sqrt(k)+1,2) if(k%i==0) return 0;
	return 1;
}
int n,a[N];
//#include<somo.h>
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n<1200) cout<<"ABC\n";
    else cout<<"ARC\n";
	return 0;
}
