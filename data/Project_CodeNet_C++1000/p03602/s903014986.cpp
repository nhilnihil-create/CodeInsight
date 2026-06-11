#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll a[512][512];
int n;ll r;

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n)scanf("%lld",&a[i][j]);
	fore(i,0,n)fore(j,i+1,n){
		bool asd=true;
		fore(k,0,n){
			if(k==i||k==j)continue;
			if(a[i][k]+a[k][j]<a[i][j]){puts("-1");return 0;}
			else if(a[i][k]+a[k][j]==a[i][j])asd=false;
		}
		if(asd)r+=a[i][j];
	}
	printf("%lld\n",r);
	return 0;
}