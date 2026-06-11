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
#define eps 1e-9
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
	int N;
	ll a[100001];
	vpll ai;
	ll ans[100001]={};
	map<ll,int> kosu;
	scan(N);
	rep(i,N){
		scan(a[i]);
		if(kosu[a[i]]==0) ai.push_back({a[i],i});
		kosu[a[i]]++;
	}
	sort(rALL(ai));
	ai.push_back({0,-1});
	vll ruii,rui;
	ll sum=0;
	int num=0;
	int nowi=ai[0].second;
	rep(i,ai.size()-1){
		sum+=ai[i].first*kosu[ai[i].first];
		num+=kosu[ai[i].first];
		//printf("i:%d ai:(%lld %lld) sum:%lld num:%d nowi:%d\n",i,ai[i].first,ai[i].second,sum,num,nowi);

		if(nowi>ai[i+1].second){
			ruii.push_back(nowi);
			rui.push_back(sum-num*ai[i+1].first);
			sum-=sum-num*ai[i+1].first;
			nowi=ai[i+1].second;
		}
		//printf("i:%d ai:(%lld %lld) sum:%lld num:%d nowi:%d\n",i,ai[i].first,ai[i].second,sum,num,nowi);
	}
	rep(i,ruii.size()){
		ans[ruii[i]]=rui[i];
	}
	rep(i,N) prin(ans[i]);
	return 0;
}
