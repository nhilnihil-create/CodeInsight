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
void solve(const int &n,const string &s,int t1,int t2){
	vi sh(n);
	sh[0]=t1;sh[1]=t2;
	for(int i=2;i<n;i++){
		sh[i]=(sh[i-1]+sh[i-2]+(s[i-1]=='x'))%2;
	}
	if((sh[n-1]+sh[0]+sh[1]+(s[0]=='x'))%2==0&&(sh[n-2]+sh[n-1]+sh[0]+(s[n-1]=='x'))%2==0){
		rep(i,n)putchar(sh[i]?'W':'S');
		exit(0);
	}
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	solve(n,s,0,0);
	solve(n,s,0,1);
	solve(n,s,1,0);
	solve(n,s,1,1);
	puts("-1");
	return 0;
}