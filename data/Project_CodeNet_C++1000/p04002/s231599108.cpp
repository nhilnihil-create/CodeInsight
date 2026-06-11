#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define SZ(a) int((a).size())
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define pb push_back
#define mp make_pair

int h,w,n;
map<PII,int> cnt;
ll res[10];

int main() {
	scanf("%d %d %d",&h,&w,&n);
	rep(i,0,n) {
		int a,b;
		scanf("%d %d",&a,&b);
		rep(dx,-2,1) rep(dy,-2,1) {
			int x=a+dx,y=b+dy;
			if (x<=0||y<=0||x+2>h||y+2>w) continue;
			cnt[mp(x,y)]++;
		}
	}
	for (auto x:cnt) res[x.second]++;
	res[0]=ll(h-2)*(w-2);
	rep(i,1,10) res[0]-=res[i];
	rep(i,0,10) printf("%lld\n",res[i]);
}
