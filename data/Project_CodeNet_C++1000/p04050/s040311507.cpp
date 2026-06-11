#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<double,double> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-9;
const int inf=2e9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	int n,m;
	cin>>n>>m;
	vi in(m);
	rep(i,m)cin>>in[i];
	if(m==1){
		cout<<in[0]<<endl;
		if(in[0]-1){
			cout<<2<<endl;
			cout<<in[0]-1<<" "<<1<<endl;
		}else{
			cout<<1<<endl;
			cout<<1<<endl;
		}
	}else{
		vi odd,even;
		rep(i,m)if(in[i]%2)odd.pb(in[i]);
		else even.pb(in[i]);
		if(odd.size()>2){
			cout<<"Impossible"<<endl;
			return 0;
		}
		sort(all(odd));
		sort(all(even));
		vi out;
		if(odd.size()){
			out.pb(odd[0]);
			odd.erase(odd.begin());
		}else{
			out.pb(even[0]);
			even.erase(even.begin());
		}
		rep(i,even.size())out.pb(even[i]);
		rep(i,odd.size())out.pb(odd[i]);
		int N=out.size();
		rep(i,N-1)cout<<out[i]<<" ";
		cout<<out[N-1]<<endl;
		out[0]++;
		out[N-1]--;
		if(out[N-1]==0)N--;
		cout<<N<<endl;
		rep(i,N-1)cout<<out[i]<<" ";
		cout<<out[N-1]<<endl;
	}
}










