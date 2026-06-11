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
	int N,x;
	scan(N>>x);
	if(2<=x&&x<=2*N-2){
		prin("Yes");
		if(N==2){
			printf("%d\n%d\n%d\n",3,2,1);
			return 0;
		}
		int ans[200001];
		ans[N-1]=x;
		if(x>2){
			ans[N]=2*N-1;
			ans[N-2]=1;
			ans[N+1]=2;
			int v=3;
			rep(i,2*N-1){
				if(N-2<=i&&i<=N+1) continue;
				while(v==x||v==2*N-1) v++;
				ans[i]=v;
				v++;
			}
		}
		else{
			ans[N]=1;
			int v=3;
			rep(i,2*N-1){
				if(i==N-1||i==N) continue;
				ans[i]=v;
				v++;
			}
		}
		rep(i,2*N-1) prin(ans[i]);
	}
	else{
		prin("No");
	}
	return 0;
}
