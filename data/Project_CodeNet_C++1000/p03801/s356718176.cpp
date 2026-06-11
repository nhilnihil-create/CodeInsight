#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int N = 1e5;
LL ans[N+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<LL,LL> freq;
	map<LL,int> smallest;
	LL total_on_board = 0;
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		LL x; cin >> x;
		total_on_board += x;
		freq[x]++;
		if(smallest.find(x)==smallest.end())
			smallest[x] = i;
	}

	LL moves = 0;
	memset(ans,0,sizeof ans);
	while(smallest[(*(--freq.end())).first] != 0) //while the largest pile is not at 1
	{
		LL largest = (*(--freq.end())).first;
		LL second_largest = (*(--(--freq.end()))).first;

		total_on_board -= (largest-second_largest)*freq[largest];
		ans[smallest[(*(--freq.end())).first]] += (largest-second_largest)*freq[largest];

		freq[second_largest] += freq[largest];
		freq.erase(largest);
		smallest[second_largest] = min(smallest[second_largest],smallest[largest]);
	}
	ans[0] = total_on_board;

	for(int i = 0; i < n; i++)
		cout<<ans[i]<<'\n';

	cout<<flush;
	return 0;
}