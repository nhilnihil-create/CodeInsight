#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main(){
    ll N, W;
    cin >> N >> W;
    map<ll, vector<ll>> wvMap;
    ll w, v;
    ll w_one;

    for(ll i = 0; i < N; ++i)
    {
    	cin >> w >> v;
    	if (i == 0)
    	{
    		w_one = w;
		    // 重さの種類は高々4種類	
    		for (ll n = w_one; n <= w_one + 3; ++n)
    		{
    			wvMap[n] = {};
    		}
    	}
    	wvMap[w].push_back(v);
    }

    for (ll i = w_one; i <= w_one + 3; ++i)
    {
		sort(wvMap[i].begin(), wvMap[i].end());
    }

    ll ans = 0;
    ll tmpW = w_one;
    ll weightSum[4];
    ll valueSum[4];
    ll allWeightSum = 0;
    ll allValueSum = 0;
    int count = 0;
    REP(i, 4)
    {
    	weightSum[i] = 0;
    	valueSum[i] = 0;
    }

    for (int i = 0; i <= wvMap[tmpW].size(); ++i)
    {
    	for(int n = 1; n <= i; ++n)
    	{
    		valueSum[count] += wvMap[tmpW][wvMap[tmpW].size() - n];
    	}
    	weightSum[count] = tmpW * i;
    	count++;
    	tmpW++;
    	for (int j = 0; j <= wvMap[tmpW].size(); ++j)
	    {
	    	for(int n = 1; n <= j; ++n)
	    	{
	    		valueSum[count] += wvMap[tmpW][wvMap[tmpW].size() - n];
	    	}
	    	weightSum[count] = tmpW * j;
	    	count++;
	    	tmpW++;
	    	for (int k = 0; k <= wvMap[tmpW].size(); ++k)
		    {
		    	for(int n = 1; n <= k; ++n)
		    	{
		    		valueSum[count] += wvMap[tmpW][wvMap[tmpW].size() - n];
		    	}
		    	weightSum[count] = tmpW * k;
		    	count++;
		    	tmpW++;
		    	for (int l = 0; l <= wvMap[tmpW].size(); ++l)
			    {
			    	for(int n = 1; n <= l; ++n)
			    	{
			    		valueSum[count] += wvMap[tmpW][wvMap[tmpW].size() - n];
			    	}
			    	weightSum[count] = tmpW * l;
			    	// 最大値を更新するか判定する
			    	allValueSum = 0;
			    	allWeightSum = 0;
			    	for (int n = 0; n < 4; ++n)
			    	{
			    		allValueSum += valueSum[n];
			    		allWeightSum += weightSum[n];
			    	}
			    	if (allWeightSum <= W) ans = max(ans, allValueSum);

			    	valueSum[count] = 0;
			    	weightSum[count] = 0;
			    }
		    	count--;
			   	tmpW--;
			    valueSum[count] = 0;
		    	weightSum[count] = 0;
		    }
	    	count--;
	    	tmpW--;
		    valueSum[count] = 0;
	    	weightSum[count] = 0;
	    }
    	count--;
    	tmpW--;
	    valueSum[count] = 0;
		weightSum[count] = 0;
	}

    cout << ans << endl;
}
