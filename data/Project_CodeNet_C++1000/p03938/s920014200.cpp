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
int main(){
	int N,p[20001];
	scan(N);
	int a[20001],b[20001];
	rep(i,N){
		a[i]=30000*i+1;
		b[i]=30000*(N-i-1)+1;
	}
	rep(i,N){
		scan(p[i]);
		p[i]--;
		a[p[i]]+=i;
	}
	rep(i,N){
		printf("%d ",a[i]);
	}
	kaigyo;
	rep(i,N){
		printf("%d ",b[i]);
	}
	kaigyo;
	return 0;
}
