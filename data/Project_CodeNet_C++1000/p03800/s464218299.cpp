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
char s[100005];
int ans[100005];
const int SHEEP=0,WOLF=1;
bool valid(){
	rep(i,n){
		int a=i;
		int b=(i+1)%n;
		int c=(i+2)%n;
		int ox=(s[b]=='x');
		if(ans[b]==WOLF)ox=1-ox;
		if(ans[a]^ox!=ans[c])return false;
	}
	return true;
}
int main(){
	scanf("%d%s",&n,s);
	rep(a,2)rep(b,2){
		ans[0]=a;ans[1]=b;
		for(int i=2;i<n;i++){
			int ox=(s[i-1]=='x');
			if(ans[i-1]==WOLF)ox=1-ox;
			ans[i]=ans[i-2]^ox;
		}
		if(valid()){
			rep(i,n)putchar(ans[i]==SHEEP?'S':'W');
			return 0;
		}
	}
	puts("-1");
	return 0;
}