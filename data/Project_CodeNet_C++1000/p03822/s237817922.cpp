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
#include <stack>
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
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<vi>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n;
	cin>>n;
	vector<vector<int>> srt(n,vector<int>());
	vector<int> dp(n,0);
	vector<int> a(n,0);
	vector<int> in(n,0);
	FOR(i,1,n){
		cin>>a[i];
		a[i]--;
		in[a[i]]++;
	}
	queue<int> q;
	FOR(i,0,n){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int nw=q.front();
		q.pop();
		int nx=a[nw];
		sort(srt[nw].rbegin(),srt[nw].rend());
		int l=srt[nw].size();
		int mx=0;
		FOR(i,0,l){
			mx=max(mx,srt[nw][i]+i+1);
		}
		dp[nw]=mx;
		//cerr<<nw<<" "<<dp[nw]<<endl;
		in[nx]--;
		srt[nx].PB(mx);
		if(in[nx]==0){
			q.push(nx);
		}
	}
	cout<<dp[0];
	return 0;
}
