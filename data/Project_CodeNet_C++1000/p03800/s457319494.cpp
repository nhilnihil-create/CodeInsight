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
int n;
char c[100005];
int r[100005];
bool hantei(int a,int b,int c,char t){
	if(t=='o'&&b==0)if(a==c)return true;else return false;
	if(t=='o'&&b==1)if(a!=c)return true;else return false;
	if(t=='x'&&b==0)if(a!=c)return true;else return false;
	if(t=='x'&&b==1)if(a==c)return true;else return false;
	return false;
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
    cin>>n;
	rep(i,n)cin>>c[i];
	rep(i,4){
		r[0]=i/2;r[1]=i%2;
		for(int j=2;j<n;j++){
			if(c[j-1]=='o')r[j]=r[j-2];
			else r[j]=1-r[j-2];
			if(r[j-1]==1)r[j]=1-r[j];
		}
		if(!hantei(r[n-2],r[n-1],r[0],c[n-1]))continue;
		if(!hantei(r[n-1],r[0],r[1],c[0]))continue;
		rep(j,n)putchar(r[j]?'W':'S');
		return 0;
	}
	puts("-1");
	return 0;
}