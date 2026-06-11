#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	LL n,k,ans=0;
	cin>>n>>k;
	pair<int,int> p[101010]={};
	FOR(i,0,n){
		int aa,bb;
		cin>>aa>>bb;
		p[i]=MP(aa,bb);
	}
	int lim=0,tmpk=k;
	while(tmpk!=0){
		tmpk>>=1;
		lim++;
	}
	FORD(i,lim+1,0){
		int mask=k;
		if(i==lim){

		}else{
			if(!(k&(1<<i)))continue;
			mask&=~(1<<i);
			FORD(j,i,0){
				mask|=1<<j;
			}
		}
		mask=~mask;
		LL tmp=0;
		FOR(j,0,n){
			if(mask&p[j].ST){

			}else{
				tmp+=p[j].ND;
			}
		}
		if(tmp>ans){
			ans=tmp;
		}
		//cerr<<i<<" "<<mask<<" "<<tmp<<endl;
	}
	cout<<ans<<endl;
    return 0;
}
