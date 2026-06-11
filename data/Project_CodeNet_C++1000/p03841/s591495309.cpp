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
bool dead[300000]={};
int ans[300000];
vpint waitpush[300000];
priority_queue<pint,vector<pint>,greater<pint> > yoyunum;
int main(){
	int N,x[502];
	int nokori[2][502];
	scan(N);
	rep(i,N){
		scan(x[i]);
		x[i]--;
		ans[x[i]]=i;
		dead[x[i]]=1;
		if(i!=0) yoyunum.push({x[i],i});
		if(i!=N-1) waitpush[x[i]+1].push_back({2*N*N-x[i],i});
	}
	rep(i,N){
		nokori[0][i]=i;
		nokori[1][i]=N-i-1;
	}
	rep(i,N*N){
		//printf("i:%d\n",i+1);
		//if(dead[i]==1) printf("ans:%d\n",ans[i]+1);
		rep(j,waitpush[i].size()){
			yoyunum.push(waitpush[i][j]);
		}
		if(dead[i]==0){
			//printf("yoyusize:%d\n",yoyunum.size());
			if(yoyunum.empty()){
				prin("No");
				return 0;
			}
			int yoyu=yoyunum.top().first;
			int kazu=yoyunum.top().second;
			//printf("yoyu:%d kazu:%d\n",yoyu,kazu+1);
			yoyunum.pop();
			ans[i]=kazu;
			if(i<x[kazu]){
				nokori[0][kazu]--;
				if(nokori[0][kazu]>0) yoyunum.push({yoyu,kazu});
			}
			else{
				nokori[1][kazu]--;
				if(nokori[1][kazu]>0) yoyunum.push({yoyu,kazu});
			}
		}
	}
	int flag=1;
	rep(i,N) if(nokori[0][i]!=0||nokori[1][i]!=0) flag=0;
	if(flag){
		prin("Yes");
		rep(i,N*N){
			printf("%d ",ans[i]+1);
		}
		kaigyo;
	}
	else prin("No");
	return 0;
}
