/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
bool check(vector<int> v){
	int cnt[2]={0};
	for(auto it:v)
		cnt[it&1]++;
	if(cnt[0]&1){
		return 1;
	}
	if(cnt[1]!=1){
		return 0;
	}
	for(auto &it:v){
		if(it&1){
			if(it==1) return 0;
			it--;
		}
	}
	int gcd=v[0];
	for(auto it:v)
		gcd=__gcd(gcd,it);
	for(auto & it:v){
		it/=gcd;
	}
	return !check(v);
}
int main(){
	vector<int> v;
	fastio;
	R(n);
	rb(i,1,n){
		int ai;
		R(ai);
		v.PB(ai);
	}	
	cout<<(check(v)? "First":"Second")<<endl;
	return 0;
}
/** 程序框架：
  *
  *
  *
  *
  **/
