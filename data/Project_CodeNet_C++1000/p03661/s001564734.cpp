#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 200005
#define INF 1000000007LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;


int main()
{
	int n;
	ll T[SIZE];
	scanf("%d",&n);
	ll a=0,s=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&T[i]);
		a += T[i];
	}
	ll minv;
	a -= T[0];
	s = T[0];
	minv = abs(a-s);
	for(int i=1;i<(n-1);i++){
		a -= T[i];
		s += T[i];
		minv = min(minv,abs(a-s));
	}

	printf("%lld\n",minv);

	return 0;
}
