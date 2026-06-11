#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define pb push_back
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[200010];
struct edge{int to,cost;};
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
bool prime(int a){
	if(a==1)return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return false;
	}
	return true;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){//線分の交差判定
	double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
	double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
	double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
	double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
	return tc*td<0&&ta*tb<0;
}
void init_fact(int n){
	kaijo[0]=1;
	for(int i=1;i<=n;i++){
		kaijo[i]=kaijo[i-1]*i;
		kaijo[i]%=MOD;
	}
}
int modpow(int a,int b){
	if(b==0)return 1;
	if(b%2)return modpow(a,b-1)*a%MOD;
	int memo=modpow(a,b/2);
	return memo*memo%MOD;
}
int comb(int a,int b){
	if(b>a)return 0;
	if(a==b)return 1;
	return kaijo[a]*modpow(kaijo[a-b],MOD-2)%MOD*modpow(kaijo[b],MOD-2)%MOD;
}
int g(int x){
	x=modpow(x,MOD-2);
	return x;
}
string s,t;
int ss[100010],st[100010],q;
signed main(){
	cin>>s>>t>>q;
	ss[0]=(s[0]=='A'?1:2),st[0]=(t[0]=='A'?1:2);
	for(int i=1;i<s.size();i++)ss[i]=ss[i-1]+(s[i]=='A'?1:2);
	for(int i=1;i<t.size();i++)st[i]=st[i-1]+(t[i]=='A'?1:2);
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		int S=ss[b]-(a==0?0:ss[a-1]);
		int T=st[d]-(c==0?0:st[c-1]);
		if(S%3==T%3)puts("YES");
		else puts("NO");
	}
	return 0;
}
