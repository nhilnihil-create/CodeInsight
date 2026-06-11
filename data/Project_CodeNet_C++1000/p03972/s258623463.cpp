#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))

i64 w;
i64 h;

int main()
{
	cin >> w >> h;
	vector<P> vec;
	rep(i,1,w)
	{
		i64 p;
		cin >> p;
		vec.push_back({p,0});
	}
	rep(i,1,h)
	{
		i64 p;
		cin >> p;
		vec.push_back({p,1});
	}
	sort(vec.begin(),vec.end());
	i64 cou[2] = {h +  1,w + 1};
	i64 result = 0;
	for(P & p : vec)
	{
		if(cou[0] == 0 && cou[1] == 0) break;
		result += cou[p.second] * p.first;
		cou[1 - p.second]--;
	}
	cout << result << endl;
}



