#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
typedef long long ll;
const int maxn=100200,P=1000000007;
int n;
int a[maxn];

int main() {
	//freopen("a.in","r",stdin);
	scanf("%d\n",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	ll ans=1,cnt=1;
	rep(i,1,n) {
		if (a[i]>=2*cnt-1) {
			ans=(ans*cnt)%P;
			cnt++;
		} else {
			ans=(ans*cnt)%P;
		}
	}
	cout<<ans<<endl;
	return 0;
}
