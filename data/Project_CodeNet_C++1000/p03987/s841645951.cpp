#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int a[200000];
int p[200001];
set<int> lt;
set<int> rt;
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		p[a[i]]=i;
	}
	lt.insert(-1);
	rt.insert(n);
	for(int i=1;i<n+1;i++)
	{
		auto l=lt.lower_bound(p[i]);
		l--;
		auto r=rt.lower_bound(p[i]);
		cerr<<(*r)<<" "<<(*l)<<endl;
		ans+=(ll)(*r-p[i])*(ll)(p[i]-*l)*(ll)i;
		lt.insert(p[i]);
		rt.insert(p[i]);
	}
	cout<<ans<<endl;
	return 0;
}