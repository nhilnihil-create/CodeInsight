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
	LL n,a,b,h[101001]={};
	cin>>n>>a>>b;
	FOR(i,0,n)cin>>h[i];
	sort(h,h+n);
	LL l=0,r=1e9,m=(l+r+1)/2,c=a-b;
	while(m!=r){
		LL cnt=0;
		FOR(i,0,n){
			if(h[i]>b*m)cnt+=(h[i]-b*m+c-1)/c;
		}
		if(cnt<=m){
			r=m;
		}else{
			l=m;
		}
		m=(l+r+1)/2;
	}
	cout<<m<<endl;



    return 0;
}
