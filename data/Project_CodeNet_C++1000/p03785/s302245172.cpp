/*
{By GWj

*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int c,k,t[100000+20];

int main(){
	fastio;
	R(n);
	R2(c,k);
	rb(i,1,n){
		R(t[i]);
	}
	sort(t+1,t+1+n);
	int l=1;
	int rest=0;
	rb(i,1,n){
		if(t[i]-t[l]>k||i-l+1>c){
			l=i;
			rest++;
		}
	}
	rest++;
	cout<<rest<<endl;
	return 0;
}