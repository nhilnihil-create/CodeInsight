#include<bits/stdc++.h>
using namespace std;
#define SC scanf
#define PR printf
#define pb push_back
#define mp make_pair
#define SZ(v) ((int)(v).size())
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define db double
#define ldb long double
#define uint unsigned
#define ll long long
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef map<int,int> mii;
const int INF=0x3f3f3f3f;
const ll LL_INF=0x3f3f3f3f3f3f3f3f;
const int xx[4]={1,-1,0,0};
const int yy[4]={0,0,1,-1};
int inline nextin(){
	int t;
	if(scanf("%d",&t)!=1)exit(0);
	return t;
}
int inline in(){
	int x=0,c;
	for(;(uint)((c=getchar())-'0')>=10;){
		if(c=='-')return -in();
		if(!~c)throw ~0;
	}
	do{
		x=(x<<3)+(x<<1)+(c-'0');
	}while((uint)((c=getchar())-'0')<10);
	return x;
}
char p[100005];
int P[100005],S[100005];
int main(){
	int n;
	scanf("%d%s",&n,p);
	for(int i=0;p[i];i++){
		if(p[i]=='o')P[i+1]=0;
		else P[i+1]=1;
	}
	P[n+1]=P[1];
	for(int i=0;i<8;i++){
		S[0]=i&1;
		S[1]=(i>>1)&1;
		S[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++){
			S[j+1]=S[j-2]^P[j];
		}
		if(S[0]^S[n]^S[1]^S[n+1]||S[1]^S[n+1]^S[2]^S[n+2])continue;
		for(int j=1;j<=n;j++){
			printf("%c",(S[j]^S[j-1])?'W':'S');
		}
		printf("\n");
		return 0;
	}
	puts("-1");
	return 0;
}