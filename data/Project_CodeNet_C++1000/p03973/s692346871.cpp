#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
	scanf("%d", &n);
	ll ans=0, b;
	for(int i=0; i<n; i++){
		ll a;
		scanf("%d", &a);
		if(i==0){
			ans+=(a-1);
			b=1;
			continue;
		}
		if(a==b+1){
			b++;
		}else{
			ans+=((a-1)/(b+1));
		}
	}
	printf("%lld\n", ans);
    return 0;
}