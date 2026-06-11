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
int zz[100005];
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	int n;
	string dat;
	cin>>n>>dat;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		zz[0]=i;zz[1]=j;
		for(int k=1;k<n-1;k++){
			zz[k+1]=zz[k]^zz[k-1]^(dat[k]=='x');
		}
		if((dat[0]=='x')==(zz[0]^zz[1]^zz[n-1])&&(dat[n-1]=='x')==(zz[0]^zz[n-1]^zz[n-2])){
			for(int k=0;k<n;k++)cout<<(zz[k]?'W':'S');
			cout<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}