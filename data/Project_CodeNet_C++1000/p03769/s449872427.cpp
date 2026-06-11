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
	LL n;
	cin>>n;
	vector<int> v;
	LL t=1,d=0;
	FOR(i,0,60){
		t*=2;
		if(t-1<=n)v.PB(i+1);
		else{
			d=i;
			t=n-(t/2-1);
			break;
		}
	}
	//cerr<<d<<" "<<t<<endl;
	int nx=d+1;
	map<int,int> ins;
	queue<int> ans;
	FORD(i,d+2,0){
		if(t>=(1LL<<i)){
			ins[i]=nx;
			t-=(1LL<<i);
			nx++;
		}
	}
	if(ins[0]!=0)ans.push(ins[0]);
	FORQ(i,1,d){
		ans.push(i);
		if(ins[i]!=0)ans.push(ins[i]);
	}
	FOR(i,1,nx)ans.push(i);

	cout<<ans.size()<<endl;
	while(ans.size()>1){
		cout<<ans.front()<<" ";
		ans.pop();
	}
	cout<<ans.front()<<endl;


    return 0;
}
