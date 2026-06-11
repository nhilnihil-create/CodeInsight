#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;



ll h,w,n;


#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int main()
{
	vector<P> point;
	cin >> h >> w >> n;
	rep(i,0,n - 1)
	{
		ll a,b;
		cin >> a >> b;

		rep(x,max(1LL,a - 2),min(h - 2,a))
		{
			rep(y,max(1LL,b - 2),min(w - 2,b))
			{
				point.push_back(P(x,y));
			}
		}
	}



	vector<int> ans(10,0);
	ll cou = 1;
	ll res = 0;
	if(!point.empty())
	{
		sort(point.begin(),point.end());
		rep(i,1,point.size() - 1)
		{
			if(point[i - 1].first == point[i].first && point[i - 1].second == point[i].second)
			{
				cou++;
			}
			else
			{
				ans[cou]++;
				res++;
				cou = 1;
			}
		}
		ans[cou]++;
		res++;
	}
	ll all = (h - 2) * (w - 2);
	cout << all - res << endl;
	rep(i,1,9)
	{
		cout << ans[i] << endl;
	}
	return 0;
}


	
