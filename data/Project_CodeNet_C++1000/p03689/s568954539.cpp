#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1ll<<(x))
#define inf 2005000
#define MOD 1000000007
#define N 200005
#define M 1000005
#define LOG 60
#define KOK 4000000
using namespace std;

int H,W,h,w;
int val[505*505],mat[505][505];

int main() {

	//freopen("input.txt","r",stdin);	

	scanf("%d %d %d %d",&H,&W,&h,&w);

	if(H%h==0 && W%w==0) {

		printf("No");

		return 0;

	}

	int rh=H%h;
	int rw=W%w;

	int total=rh*w+rw*h-rh*rw;
	int oth=H*W-total;

	val[1]=-505*total-1;

	int cnt=0;

	printf("Yes\n");

	for(int i=1;i<=h;i++) {

		for(int j=1;j<=w;j++) {

			if(i<=rh || j<=rw) mat[i-1][j-1]=505;
			else {

				mat[i-1][j-1]=val[++cnt];

			}

		}

	}

	for(int i=0;i<H;i++) {

		for(int j=0;j<W;j++) {

			printf("%d ",mat[i%h][j%w]);

		}

		puts("");

	}

}

