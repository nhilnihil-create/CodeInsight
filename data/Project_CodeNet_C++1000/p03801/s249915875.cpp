#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000






int main() {
	vector<pair<long long, long long> >a;
	long long b[N];
	f(i, N)b[i] = 0;
	long long n, k, kk;
	long long x, y, z;
	long long s, ss, ans;
	bool v = true;
	ans = 0;
	ss = 0;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &x);
		ss += x;
		a.push_back(make_pair(-x, i));
	}
	sort(a.begin(), a.end());
	k = a[0].second;
	s = 0;//石sum
	ans = 0;
if(k==0){
  b[0]=ss;
  	f(i, n) {
		printf("%lld\n", b[i]);
	}  
 return 0; 
}
	f(i, n) {
		kk = a[i].second;
		if (kk < k) {
			x = s + (i*(a[i].first));
			b[k] = x - ans;
			ans = x;
			k = kk;
			if (k == 0) {
				b[0] = ss - ans;
				break;
			}
		}
		s -= a[i].first;

	}
	f(i, n) {
		printf("%lld\n", b[i]);
	}

	return 0;
}