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
int dat[100005];

#define MOD (1000000007LL)


lli fact(int x){
	lli res=1;
	rep(i,x)res = (res * ((lli)(i+1))) % MOD;
	return res;
}

int main(void){
	//printf("%lld\n",(12LL*fact(12)) % MOD);
	lli ans=1;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&dat[i]);
	
	lli nsr = 0;
	rep(i,n){
		if(dat[i]<nsr*2+1){
			ans = ((nsr+1) * ans) % MOD;
		}
		else nsr++;
	}
	ans = (ans * fact(nsr)) % MOD;
	printf("%lld\n",ans);
	
	return 0;
}




