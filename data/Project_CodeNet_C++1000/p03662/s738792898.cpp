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
int dis1[100000+10],dis2[100000+10];
void dfs(int now,int p,int col,int diss){
	if(col) dis2[now]=diss;
	else dis1[now]=diss;
	for(auto it: each[now]){
		if(it!=p) dfs(it,now,col,diss+1);
	}
}
int main(){
	int n;
	cin>>n;
	rep(i,n-1){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		each[xi].PB(yi),each[yi].PB(xi);
	}
	dfs(1,-1,0,1),dfs(n,-1,1,1);
	int tot1,tot2;
	tot1=tot2=0;
	rb(i,1,n){
		if(dis1[i]<=dis2[i]) tot1++;
		else tot2++;
	}
	if(tot1>tot2) cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}
