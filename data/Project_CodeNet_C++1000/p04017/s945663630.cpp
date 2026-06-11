#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int r[22][100001]={};//r[0][i]は番兵
int main(){
	int N,Q;
	ll L,x[100001];
	scan(N);
	rep(i,N) scan(x[i]);
	scan(L>>Q);
	rep(i,N){
		r[1][i]=upper_bound(x,x+N,x[i]+L)-x-1;
	}
	rep1(k,20){
		rep(i,N){
			r[k+1][i]=r[k][r[k][i]];
		}
	}
	rep(i,Q){
		int a,b;
		scan(a>>b);
		a--; b--;
		if(a>b) swap(a,b);
		int nowans=0;
		while(1){
			int daymin=0,daymax=20;
			while(daymin+1<daymax){
				int daymid=(daymin+daymax)/2+(daymin+daymax)%2;
				//printf("a:%d b:%d min:%d max:%d mid:%d r:%d\n",a,b,daymin,daymax,daymid,r[daymid][a]);
				if(r[daymid][a]<b) daymin=daymid;
				else daymax=daymid;

			}
			//kaigyo;
			if(daymin==0) break;
			else{
				nowans+=(1<<(daymin-1));
				a=r[daymin][a];
			}
		}
		prin(nowans+1);
	}
	return 0;
}
