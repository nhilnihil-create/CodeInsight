//* AuThOr GaRyMr *//
//Codeforces ID: GaryMr
//Atcoder ID: Gary
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[100000+10];
int Size[100000+10];int n;
int color[100000+10],all;
int dfs(int now,int p){
	if(each[now].size()==1&&p!=-1) {
	return Size[now]=1;
	}
	int tmps;
	tmps=1;
	for(auto it: each[now]){
		if(it!=p){
			tmps+=dfs(it,now);
		} 
	}
	return Size[now]=tmps;
}
void dfs2(int now,int p,int dis){
	if(now==n) {
		all=dis;
//		cout<<all<<endl;
		color[now]=1;
		return ;
	}
	for(auto it:each[now]){
		if(it!=p){
			dfs2(it,now,dis+1);
			color[now]|=color[it]; 
		}
	}
}
int diV;
int belong;
void dfs3(int now,int p,int is){
	if(is==belong) diV=now;
	else
	for(auto it: each[now]){
		if(it!=p&&color[it]){
			dfs3(it,now,is+1);
			return;
		}
	}
}
int main(){
	
	cin>>n;
	rep(i,n-1){
		int xi,yi;
		cin>>xi>>yi;
		each[xi].PB(yi),each[yi].PB(xi);
	}
	dfs(1,-1);
	dfs2(1,-1,1);
	belong=all/2+all%2;
	belong++;
	dfs3(1,-1,1); 
	int one,two;
	two=Size[diV],one=n-two;
	if(one>two) cout<<"Fennec";
	else cout<<"Snuke"; 
	return 0;
}
