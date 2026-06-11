//
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>
#include<cmath>

#include<cstring>
#include<string>
#include<cctype>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<list>

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;

const int OO=(int)2e9;
const ll INF=(ll)4e18;
const double EPS=(double)1e-12;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

#define INL(i,a,b) ((a<=i)&&(i<=b))
#define EXL(i,a,b) ((a< i)&&(i< b))
#define REPP(i,a,b,c) for(int i=a;i<=b;i+=c)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,c) for(int i=a;i>=b;i-=c)
#define REV(i,a,b) REVV(i,a,b,1)
using namespace std;

const int MOD=(int)1e9 + 7;

int n,m;
ll a,b;
ll rea,reb;

int main(){
	scanf("%d %d",&n,&m);
	rea=0;
	scanf("%lld",&a);
	REP(i,1,n-1){
		scanf("%lld",&b);
		rea=(rea+((((b-a)%MOD)*i)%MOD*((n-i)%MOD))%MOD)%MOD;
		a=b;
	}
	reb=0;
	scanf("%lld",&a);
	REP(i,1,m-1){
		scanf("%lld",&b);
		reb=(reb+((((b-a)%MOD)*i)%MOD*((m-i)%MOD))%MOD)%MOD;
		a=b;
	}
	printf("%lld\n",(rea*reb)%MOD);
	return 0;
}