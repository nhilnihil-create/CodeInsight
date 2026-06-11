/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m,a[105];
int get(vector<int>&v){
	int ret=v.back();v.pop_back();return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	vector<int>odd,even;
	for(int i=1;i<=m;i++){
		if(a[i]&1)odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	if(odd.size()>2){
		puts("Impossible");
		return 0;
	}
	vector<int>A,B;
	if(odd.size())A.push_back(get(odd));
	for(auto v:even)A.push_back(v);
	if(odd.size())A.push_back(get(odd));
	B.push_back(A[0]-1);
	for(int i=1;i<A.size();i++){
		B.push_back(A[i]);
	}
	B.back()++;
	if(m==1){
		B.clear();
		B.push_back(a[1]-1);
		B.push_back(1);
	}
	for(auto v:A)cout<<v<<" ";cout<<endl;
	int tot=0;
	for(auto v:B){
		if(v)tot++;
	}
	cout<<tot<<endl;
	for(auto v:B)if(v)cout<<v<<" ";cout<<endl;
	return 0;
}