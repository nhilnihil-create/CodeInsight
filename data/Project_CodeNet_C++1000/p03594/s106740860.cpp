#include <bits/stdc++.h>
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
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int h,w,d;

int main(){
	cin>>h>>w>>d;
	int D=2*d;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int x=(i+j)%D,y=(i-j+1000*D)%D;
			if(x>=d&&y>=d) cout<<'R';
			if(x>=d&&y<d) cout<<'Y';
			if(x<d&&y>=d) cout<<'G';
			if(x<d&&y<d) cout<<'B';
		}
		cout<<endl;
	}
}