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
	int n;
	cin>>n;
	vector<vector<int>> v=vector<vector<int>>(n+2,vector<int>());
	int db[101010]={};
	int dw[101010]={};
	FOR(i,1,n){
		int a,b;
		cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	db[1]=dw[n]=1;
	queue<int> b;
	queue<int> w;
	b.push(1);
	w.push(n);
	while(b.size()){
		int t=b.front();
		b.pop();
		int l=v[t].size();
		FOR(i,0,l){
			if(db[v[t][i]]==0){
				db[v[t][i]]=db[t]+1;
				b.push(v[t][i]);
			}
		}
	}
	while(w.size()){
		int t=w.front();
		w.pop();
		int l=v[t].size();
		FOR(i,0,l){
			if(dw[v[t][i]]==0){
				dw[v[t][i]]=dw[t]+1;
				w.push(v[t][i]);
			}
		}
	}
	int cb=0,cw=0;
	FORQ(i,1,n){
		if(db[i]<=dw[i]){
			cb++;
		}else{
			cw++;
		}
	}
	if(cb<=cw){
		cout<<"Snuke"<<endl;
	}else{
		cout<<"Fennec"<<endl;
	}

    return 0;
}
