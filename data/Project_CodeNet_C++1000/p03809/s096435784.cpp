#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

int n;
vector<int> vs[100005];
lli A[100005];
lli pn[100005];

bool dfs(int no,int pa){
	lli cs=0,mcs=0;
	bool isha=true;
	rep(i,vs[no].size()){
		int to=vs[no][i];
		if(to==pa)continue;
		if(!dfs(to,no))return false;
		cs += pn[to];
		mcs = max(mcs,pn[to]);
		isha=false;
	}
	if(isha){
		pn[no]=A[no];
		return true;
	}
	pn[no]=A[no]*2-cs;
	mcs = max(mcs,pn[no]);
	//printf("%d :: %lld %lld %lld %lld\n",no,A[no],pn[no],cs,mcs);
	
	if(pn[no]<0 || mcs>A[no])return false;
	return true;
}

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&A[i]);
	rep(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b); a--; b--;
		vs[a].push_back(b);
		vs[b].push_back(a);
	}
	int st=0;
	rep(i,n){
		if(vs[i].size()==1)st=i;
	}
	
	puts((dfs(st,-1) && pn[st]==A[st])?"YES":"NO");
	
	return 0;
}
