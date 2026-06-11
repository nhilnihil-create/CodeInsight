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
	ll N;
	ll A[100001],sum=0;
	scan(N);
	rep(i,N){
		scan(A[i]);
		sum+=A[i];
	}
	ll kaisu;
	if(sum%(N*(N+1)/2)!=0){
		prin("NO"); return 0;
	}
	else{
		kaisu=sum/(N*(N+1)/2);
	}
	int flag=1;
	ll dansanum=0;
	rep(i,N){
		if((kaisu-(A[(i+1)%N]-A[i]))>=0&&(kaisu-(A[(i+1)%N]-A[i]))%N==0){
			dansanum+=(kaisu-(A[(i+1)%N]-A[i]))/N;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag&&dansanum==kaisu){
		prin("YES");
	}
	else prin("NO");
	return 0;
}
