#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
#define fi first
#define queue QQQ
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 2e5+233; 
int a[maxn],n,ans=0;
bool check(int limit){
	rep(i,0,n){
		if(a[n-i]>=limit&&a[n-i-1]>=limit) return 1;
		if(a[n-i]<limit&&a[n-i-1]<limit) return 0;
		if(a[n+i]>=limit&&a[n+i+1]>=limit) return 1;
		if(a[n+i]<limit&&a[n+i+1]<limit) return 0;
	}
	return a[1]>=limit;
}
int main(){
	n = rd();
	Rep(i,1,2*n-1) a[i] = rd();
	int l = 1,r = 2*n+1;
	while(l <= r){
		int mid = (l+r) >> 1;
//		printf("[%d %d]\n",mid,check(mid));
		if(check(mid) == 1){
			l = mid + 1;
			ans = mid;
		} else{
			r = mid - 1;
		}
	}writeln(ans);
	return 0;
}




/*	for (int i=0;i<n-1;i++){
		int s0=0,s1=0;
		if (a[n-i]>=mid&&a[n-i-1]>=mid) s1++;
		if (a[n-i]<mid&&a[n-i-1]<mid) s0++;
		if (a[n+i]>=mid&&a[n+i+1]>=mid) s1++;
		if (a[n+i]<mid&&a[n+i+1]<mid) s0++;
		if (s1) return 1;
		if (s0) return 0;
	}
*/