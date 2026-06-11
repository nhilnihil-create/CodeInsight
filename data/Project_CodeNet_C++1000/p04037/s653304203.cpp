#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=1e5+10;
int n,a[N]; 
int main() {
	rd(n);
	for(int i=0;i<n;++i) rd(a[i]);
	sort(a,a+n,greater<int>());
	int x=0,y=0;
	while(y+1<a[x+1]) x++,y++;
	
	int t1=!((a[x]-(y+1))&1);
	int r=x; while(y<a[r+1]) r++;
	int t2=!((r+1-(x+1))&1);
	
	if(!(t1&t2)) printf("First");
	else printf("Second");
	return 0;
}