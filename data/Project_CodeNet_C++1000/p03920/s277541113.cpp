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
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<28;
const ll INF=1ll<<50;
const double pi=acos(-1);
const double eps=1e-8;
const int mod=1e9+7;
const vi emp;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

int n;

int main(){
	cin>>n;
	int sum=0;
	vi a;
	int flag;
	for(int i=1;i<=n;i++){
		sum+=i;
		a.push_back(i);
		if(sum>=n){
			flag=sum-n;
			break;
		}
	}
	for(int i=0;i<a.size();i++) if(a[i]!=flag) cout<<a[i]<<endl;
}