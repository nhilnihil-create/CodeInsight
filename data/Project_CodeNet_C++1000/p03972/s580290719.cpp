#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll MOD = 1e9+7;
P pq[200001];
int main()
{
	int w,h;
	ll ans=0;
	cin>>w>>h;
	for(int i=0;i<w+h;i++)
	{
		ll tmp;
		cin>>tmp;
		if(i>=w)
			pq[i]=P(tmp,1);
		else
			pq[i]=P(tmp,0);
	}
	sort(pq,pq+w+h);
	ll tate=h+1;
	ll yoko=w+1;
	for(int i=0;i<w+h;i++)
	{
		if(pq[i].second)
		{
			ans+=yoko*pq[i].first;
			tate--;
		}else{
			ans+=tate*pq[i].first;
			yoko--;
		}
	}
	cout<<ans<<endl;
	return 0;
}