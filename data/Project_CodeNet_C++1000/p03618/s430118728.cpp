#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main()
{
	string a;
	int cnt[26];
	ll ans=0;
	cin>>a;
	fill(cnt,cnt+26,0);
	for(int i=0;i<a.size();i++)
		cnt[a[i]-'a']++;
	ans=(ll)a.size()*((ll)a.size()-1LL)/2;
	for(int i=0;i<26;i++)
		ans-=(ll)cnt[i]*(ll)(cnt[i]-1)/2;
	ans++;
	cout<<ans<<endl;
	return 0;
}