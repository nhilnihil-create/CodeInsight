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
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
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
int main(){
	int N,M,A[100001];
	ll costsum=0;
	ll rui[200002]={};
	scan(N>>M);
	rep(i,N){
		scan(A[i]);
		A[i]--;
	}
	rep(i,N-1){
		costsum+=(A[i+1]+M-A[i])%M;
		int beg=A[i],las=A[i+1];
		if(las<beg){
			las+=M;
		}
		rui[beg+2]++;
		rui[las+1]-=las-beg;
		rui[las+2]+=las-beg-1;
	}
	rep1(i,2*M+1){
		rui[i]+=rui[i-1];
	}
	rep1(i,2*M+1){
		rui[i]+=rui[i-1];
	}

	ll reducemax=0;
	rep(i,M){
		reducemax=max(reducemax,rui[i]+rui[i+M]);
	}
	prin(costsum-reducemax);
	return 0;
}
