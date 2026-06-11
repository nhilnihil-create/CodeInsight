#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,a,b,k;
vector<pair<ll,ll>> v;
int main()
{
			// #ifndef ONLINE_JUDGE
  	// 		// for getting input from input.txt
  	// 		freopen("input.txt", "r", stdin);
  	// 		// for writing output to output.txt
  	// 		freopen("output.txt", "w", stdout);
  	// 	#endif
  			cin>>n>>k;
  			for (int i = 0; i < n; ++i)
  			{
  				cin>>a>>b;
  				v.push_back(make_pair(a,b));
  			}
  			sort(v.begin(), v.end());
  			
  			for (int i = 0; i < v.size(); ++i)
  			{
  				k = k - v[i].second;
  				if(k<=0) { cout<<v[i].first<<endl; break; }
  			}
	return 0;
}