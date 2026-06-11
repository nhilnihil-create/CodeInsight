#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<57;
const double pi=acos(-1);
const double eps=1e-6;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,1,1,1,0},DY[8]={1,0,-1,-1,-1,0,1,1};

//1 2 3 4 = 2^4-1
//1 2 3 5 4 = 2^4-1+2^3

ll n;

int main(){
	cin>>n;
	n++;
	vi a;
	for(int i=50;i>=0;i--) if(n&1ll<<i){
		for(int j=0;j<i;j++) a.push_back(j+1);
		break;
	}
	int S=a.size(),I=S+1;
	for(int i=S-1;i>=0;i--) if(n&1ll<<i){
		a.insert(a.begin()+i,I);
		I++;
	}
	for(int i=1;i<I;i++) a.push_back(i);
	S=a.size();
	cout<<S<<endl;
	for(int i=0;i<S;i++){
		if(i) cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
}