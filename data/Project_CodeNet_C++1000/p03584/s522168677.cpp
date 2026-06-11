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
	int n, k;
	scanf("%d %d", &n, &k);
	multimap<int, ll> mp;
	for(int i=0; i<n; i++){
		int a;
		ll b;
		scanf("%d %lld", &a, &b);
		mp.insert(make_pair(a, b));
	}
	ll ans=0;
	for(auto p:mp){
		int a=p.first;
		bool e=1;
		for(int j=0; j<30; j++){
			if(((a>>j)&1)==1 && ((k>>j)&1)==0){
				e=0;
				break;
			}
		}
		if(e) ans+=p.second;
	}
	for(int i=29; i>=0; i--){
		if(((k>>i)&1)==0) continue;
		ll ans1=0;
		for(auto p:mp){
			int a=p.first;
			if(((a>>i)&1)==1) continue;
			bool e=1;
			for(int j=i+1; j<30; j++){
				if(((a>>j)&1)==1 && ((k>>j)&1)==0){
					e=0;
					break;
				}
			}
			if(e) ans1+=p.second;
		}
		if(ans<ans1) ans=ans1;
	}
	cout<<ans<<endl;
    return 0;
}