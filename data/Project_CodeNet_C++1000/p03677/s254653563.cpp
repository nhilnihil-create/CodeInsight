#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 924844033 
#define N 100005
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,m;
int a[N],pind[N<<1];
ll pre[N<<1],dc[N<<1];
ll ans;

int main() {

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++) {

		scanf("%d",&a[i]);

		if(i-1) {

			if(a[i]<a[i-1]) a[i]+=m;

			pind[a[i-1]+1]--;
			pind[a[i]+1]++;

			pre[a[i-1]+1]+=a[i-1]+1;
			pre[a[i]+1]-=a[i-1]+1;

			ans+=a[i]-a[i-1];
			
			if(a[i]>m) a[i]-=m;

		}

	}

	ll d=0;

	for(int i=1;i<=2*m;i++) {

		pind[i]+=pind[i-1];
		pre[i]+=pre[i-1];

		int ind=i>m?i-m:i;

		dc[ind]+=(ll)pind[i]*i+pre[i];

		umin(d,dc[ind]);

	}

	printf("%lld",ans+d);

}