/*
Nearly 崩溃！！！做了一天 
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
mp ant[100000+1];
LL n,l,t; 
int main(){
	fastio;
	cin>>n>>l>>t;
	LL cur=0;
	vector<LL> v;
	rb(i,1,n){
		cin>>ant[i].FIR>>ant[i].SEC;
		if(ant[i].SEC==2) ant[i].SEC=-1;
		v.PB(((LL)ant[i].FIR+ant[i].SEC*t+(LL)l*t)%l);
		cur+=(ant[i].FIR+ant[i].SEC*t)/l;
		if((ant[i].FIR+ant[i].SEC*t)%l<0) cur--;
	}
	sort(ALL(v));
	cur=(cur%n+n)%n;
//	cout<<cur<<endl;
	rb(i,cur,v.size()-1) cout<<v[i]<<endl;
	rep(j,cur) cout<<v[j]<<endl;
	return 0;
}
