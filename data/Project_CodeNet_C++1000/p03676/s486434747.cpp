#include <cstdio>

int n;
int a[200010];
long long D = 1000000007;
long long f[200010], u[200010];
long long res = 0;
int have[200010];

long long pw2(long long x, long long aa)
{
	long long y = 1;
	while(aa>0){
		if(aa % 2 == 1){
			y *= x;
			y %= D;
		}
		aa /= 2;
		x *= x;
		x %= D;
	}
	return y;
}

void pre()
{
	int i;
	f[0] = f[1] = 1;
	for(i=2; i<=n; i++){
		f[i] = f[i-1] * i;
		f[i] %= D;
	}
	u[0] = u[1] = 1;
	for(i=2; i<=n; i++){
		u[i] = pw2(f[i], D-2);
	}
}

//long long calcC(long long nn, long long mm)
long long calcC(int nn, int mm)
{
	//long long nn = nni;
	//long long mm = mmi;
	if(nn < mm)
		return 0;
	long long r = f[nn];
	r *= u[mm];
	r %= D;
	r *= u[nn-mm];
	r %= D;
	return r;
}

void solve()
{
	pre();
	int i;
	int vv, ll=-1, rr=-1;
	for(i=0; i<n+1; i++){
		have[a[i]] ++;
		if(have[a[i]] == 2)
			vv = a[i];
	}
	for(i=0; i<n+1; i++){
		if(a[i] == vv){
			if(ll==-1)
				ll = i;
			else
				rr = i;
		}
	}
	printf("%d\n", n);
	for(i=2; i<=n; i++){
		res = 0;
		res += calcC(n-1, i);
		res += calcC(n-1, i-1);
		res %= D;
		res += calcC(n-1, i-1);
		res %= D;
		res += D;
		res -= calcC(n+1-(rr-ll+1), i-1);
		res %= D;
		res += calcC(n-1, i-2);
		res %= D;
		printf("%lld\n", res);
	}
	printf("%d\n", 1);
}

int main()
{
	int i;
	scanf("%d", &n);	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	solve();
	return 0;
}