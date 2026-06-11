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
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define sz(s) s.size()
#define all(s) (s.begin(),s.end())

const int maxn=100005;
int h,w,n,sum;
map<pii,int>mp;
int ans[10];

bool on(int x,int y){
	return x>=0&&y>=0&&x+2<h&&y+2<w;
}

int main(){
	scanf("%d%d%d",&h,&w,&n);
	rep(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		for(int i=x-2;i<=x;i++)for(int j=y-2;j<=y;j++)
		if(on(i,j))mp[mk(i,j)]++;
	}
	for(map<pii,int>::iterator it=mp.begin();it!=mp.end();it++){
		ans[it->se]++;
		sum++;
	}
	printf("%lld\n",(ll)(h-2)*(ll)(w-2)-(ll)sum);
	REP(i,9)printf("%d\n",ans[i]);
	return 0;
}