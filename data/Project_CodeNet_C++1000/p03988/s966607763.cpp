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
	int N,a[101];
	scan(N);
	rep(i,N) scan(a[i]);
	sort(a,a+N);
	int amin=a[0],amax=a[N-1];
	int anum[101]={};
	rep(i,N) anum[a[i]]++;
	int flag=1;
	for(int i=amin+1;i<=amax;i++){
		if(anum[i]<=1) flag=0;
	}
	if((amax+1)/2!=amin) flag=0;
	if(amax%2){
		if(anum[amin]!=2) flag=0;
	}
	else{
		if(anum[amin]!=1) flag=0;
	}
	if(flag) prin("Possible");
	else prin("Impossible");
	return 0;
}
