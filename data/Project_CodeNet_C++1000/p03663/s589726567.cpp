
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring> 
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define repd(i,n) for(int (i)=n-1;(i)>=0;i--)
#define REPD(i,n) for(int (i)=n;(i)>0;i--) 
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define sz(s) s.size()
#define all(s) (s.begin(),s.end())

char readchar(){
	char c;
	while(c=getchar(),c!='Y'&&c!='N');
	return c;
} 

int digit=1;
char ans,junk;

bool check(ll x){
	printf("? %lld\n",x-1);
	fflush(stdout);
	ans=readchar();
	if(ans=='N')return true;
	return false;
}

ll guess(ll base){
	int l=0,r=10;
	while(r-l>1){
		ll mid=(l+r)/2;
		printf("? %lld\n",(base*10+mid)*(ll)INF); 
		fflush(stdout);
		ans=readchar();
		if(ans=='Y')r=mid;
		else l=mid;
	}
	if(check((base*10+(ll)r)*INF))return base*10+(ll)r;
	return base*10+(ll)l;
}

int main(){
	ll cur=1;
	REP(i,10){
		cur*=10;
		digit++;
		printf("? %lld\n",cur);
		fflush(stdout);
		ans=readchar();
		if(ans=='N')break;
	}
	if(digit>10){
		cur=10;
		digit=1;
		REP(i,9){
			printf("? %lld\n",cur-1);
			fflush(stdout);
			ans=readchar();
			if(ans=='Y')break;
			digit++;
			cur*=10;
		}
		printf("! %lld",cur/10);
		return 0; 
	}
	digit--;
	cur=0;
	REP(i,digit){
		ll now=guess(cur);
		cur=now;
	}
	printf("! %lld",cur);
	fflush(stdout);
	return 0;
}