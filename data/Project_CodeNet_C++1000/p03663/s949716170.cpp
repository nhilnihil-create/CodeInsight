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

int dig(LL a){
	int c=0;
	while(a>0){
		c++;
		a/=10;
	}
	return c;
}

int main(){
	LL digit=0,nw=1;
	FOR(i,0,11){
		cout<<"? "<<nw<<endl;
		string s;
		cin>>s;
		if(s=="N"){
			digit=i;
			break;
		}
		nw*=10;
	}
	if(digit==0){
		nw=2;
		FOR(i,0,11){
			cout<<"? "<<nw<<endl;
			string s;
			cin>>s;
			if(s=="Y"){
				digit=i+1;
				nw/=2;
				cout<<"! "<<nw<<endl;
				return 0;
			}
			nw*=10;
		}
	}

	LL l=1,r=10,m=(l+r)/2;
	FOR(i,1,digit){
		l*=10;r*=10;
	}
	m=(l+r)/2;
	FOR(i,0,64){
		if(l==m){
			cout<<"! "<<m+1<<endl;
			return 0;
		}
		string q=to_string(m)+"0";
		cout<<"? "<<q<<endl;
		string s;
		cin>>s;
		if(s=="N"){
			l=m;
		}else{
			r=m;
		}
		m=(r+l)/2;
	}
	cout<<"! "<<m<<endl;

    return 0;
}
