
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define output(x) cout<<x<<endl;
typedef long long int ll;



int main()
{
	ll  i, j, k, l, m, sum, flag, N, x, y, M, K;
	sum = 0;
	flag = 0;
	cin >> N;
	vector<ll>p(N);
	REP(i, 0, N) {
		cin >> p[i];
	}
	i = 0;
	j = 0;
	ll ans = 0;
	while (i < N) {
		if (p[i] == i + 1) {
			j++;
			i++;
		}
		else {
			if (j != 0) {
				ans += (j - 1) / 2 + 1;
			}
			
			j = 0;
			i++;
		}
	}
	if (j != 0) {
		ans += (j-1) / 2 + 1;
	}
	output(ans);
	
	return 0;
}











