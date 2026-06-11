/*************************************************************************
	> File Name: pyramid.cpp
	> Author: wangyifan
	> Created Time: 2019年11月07日 星期四 08时33分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define REP(i,a,b) for(register int i = a;i <= b;++i)
using namespace std;
const int maxn = 1e6+10;
int a[maxn],b[maxn];
int ans,n,num;
inline int read(){
	int res = 0,tmp = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')tmp = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9')res = (res<<1)+(res<<3)+(ch^48),ch = getchar();
	return res*tmp;
}
inline bool check(int x){
	REP(i,1,num)b[i] = a[i]>x;
	REP(i,0,n-1){
		if((b[n+i] && b[n+i+1]) || (b[n-i] && b[n-i-1]))return false;
		if((!b[n+i] && !b[n+i+1]) || (!b[n-i] && !b[n-i-1]))return true;
	}
	return a[1] <= x;
}
int main(){
	n = read();
	num = (n<<1)-1;
	REP(i,1,num)a[i] = read();
	int l = 1,r = num;
	while(l < r){
		int mid = (l+r)>>1;
		if(check(mid))ans = mid,r = mid;
		else l = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}