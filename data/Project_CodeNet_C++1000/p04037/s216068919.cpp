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
int n;
int a[100005]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	vector<int>len;
	len.push_back(1);
	for(int i=1;i<=n;i++){
		if(i>1&&len.back()==1){
			len.pop_back();
			len.push_back(a[i]-a[i-1]+2);
		}else len.push_back(a[i]-a[i-1]+1);
	}
	int cur=0;
	for(int i=0;i<len.size();i++){
//		cerr<<i<<" "<<len[i]<<endl;
		cur+=len[i];
		if(cur>n){
			cout<<((cur-n)%2?"First":"Second")<<endl;
			return 0;
		}
	}
	return 0;
}