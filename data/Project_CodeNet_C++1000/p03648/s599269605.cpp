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
	LL k,a[55]={};
	cin>>k;
	int n=50;
	if(k<50){
		FOR(i,0,(k%n))a[i]=50;
	}else{
		FOR(i,0,n)a[i]+=50+(k/n-1);
		int t=k%n;
		FOR(ii,0,t){
			a[ii]+=n;
			FOR(jj,0,n){
				if(ii!=jj)a[jj]--;
			}
		}
	}
	cout<<n<<endl;
	FOR(i,0,n){
		if(i!=n-1){
			cout<<a[i]<<" ";
		}else{
			cout<<a[i]<<endl;
		}
	}
    return 0;
}
