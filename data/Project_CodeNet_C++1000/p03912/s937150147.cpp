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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int main(){
	int n,m;
	cin>>n>>m;
	vi cnt(100010);
	rep(i,n){
		int a;
		cin>>a;
		cnt[a]++;
	}
	vi in1(m),in2(m);
	rep(i,100010){
		int t=cnt[i];
		in1[i%m]+=t%2;
		in2[i%m]+=t/2*2;
	}
//	rep(i,m)cout<<in1[i]<<" "<<in2[i]<<endl;
	int out=(in1[0]+in2[0])/2;
	loop(i,1,(m+1)/2){
		int t=m-i;
		int mi=min(in1[i]+in2[i],in1[t]+in2[t]);
		out+=mi;
		int a=mi;
		a-=in1[i];
		out+=(in2[i]-(a>0?a:0))/2;
		a=mi;
		a-=in1[t];
		out+=(in2[t]-(a>0?a:0))/2;
//		cout<<out<<endl;
	}
	if(m%2==0){
		out+=(in1[m/2]+in2[m/2])/2;
	}
	cout<<out<<endl;
}






