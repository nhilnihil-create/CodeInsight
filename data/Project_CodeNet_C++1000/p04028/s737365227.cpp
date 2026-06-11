#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const LL M=1e9+7;
const int L=5000;
int N;
string s;
LL dp[L+2][L+2];
LL dp2[L+2];
LL ps[L+2];
int f(int N,int s){
	LL ret=0;
	for(int i=0;i<N;i++){
		int d=N-i-s;
		int v=i==0?1:dp2[i-1];
		if(d>=0&&d%2==0){
			//cerr << i << ", " << dp2[i] << ", " << dp[N-i][s] << ", " << ps[d/2] << endl;
			ret+=v*dp[N-i][s]%M*ps[d/2]%M;
			ret%=M;
		}
	}
	return ret;
}
// a>=0, b>=0, x*a+y*b=gcd>=0, a>0,b>0=>abs(y)<=a,abs(x)<=b
LL gcdex(LL a,LL b,LL& x, LL& y){
	LL ax=1,ay=0;
	LL bx=0,by=1;
	while(b){
		LL r=a/b;
		LL t=a-r*b; a=b; b=t;
		LL tx=ax-r*bx; ax=bx; bx=tx;
		LL ty=ay-r*by; ay=by; by=ty;
	}
	x=ax;
	y=ay;
	return a;
}

LL modinv(LL a, LL m){
	LL x,y;
	gcdex(a,m,x,y);
	if(x<0){
		x+=m;
	} else if(x>=m){
		x-=m;
	}
	return x;
}
// powmod p^n%mod
LL powmod(LL p,LL n,LL mod){
	LL q=p%mod;
	LL pow=1;
	while(n){
		if(n&1){
			pow*=q;
			pow%=mod;
		}
		q=q*q;
		q%=mod;
		n/=2;
	}
	return pow;
}
map<string,int> cnt;
void g(int rem,string cur){
	if(rem==0){
		cnt[cur]++;
		return;
	}
	g(rem-1,cur+"0");
	g(rem-1,cur+"1");
	if(cur.size()){
		cur.pop_back();
	}
	g(rem-1,cur);
}
int main() {
	cin >> N >> s;
	ps[0]=1;
	for(int i=1;i<=L;i++){
		ps[i]=ps[i-1]*2%M;
	}
	dp[0][0]=1;
	for(int k=1;k<=N;k++){
		for(int l=0;l<=k;l++){
			if(l>0){
				dp[k][l]=2*dp[k-1][l-1]%M;
			}
			else{
				dp[k][l]=dp[k-1][l];
			}
			dp[k][l]+=dp[k-1][l+1];
			dp[k][l]%=M;
		}
	}
	cout << dp[N][s.size()]*modinv(powmod(2,s.size(),M),M) %M<< endl;

	return 0;
}

