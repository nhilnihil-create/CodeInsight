#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
int m;
int l[300010];
int r[300010];

typedef pair<int,int> P;
typedef pair<int,P> P2;

vector<P2> lenght;

void input()
{
	cin >> n >> m;

	for(int i = 0;i < n;i++)
	{
		cin >> l[i] >> r[i];

		lenght.push_back(P2(r[i] - l[i] + 1 , P(l[i] , r[i])));
	}

	sort(lenght.begin(),lenght.end());
}


struct BIT
{
	vector<int> bit;
	int n;

	BIT(int N)
	{
		N++;
		n = N;
		bit.resize(n , 0);
	}

	int sum(int i)
	{
		if(!i) return 0;
		return bit[i] + sum(i - (i & -i));
	}

	void add(int i ,int x)
	{
		if(i > n) return;
		bit[i] += x;

		add(i + (i & -i), x);
	}
};



int main()
{
	input();
	int i = 0;

	BIT bit_a(m + 2);

	for(int d = 1;d <= m;d++)
	{
		int ans = 0;
		
		for(;i < lenght.size();i++)
		{
			if(lenght[i].first > d)
			{
				break;
			}
			bit_a.add(lenght[i].second.first,1);
			bit_a.add(lenght[i].second.second + 1,-1);
		}
		for(int now = d;now <= m;now += d)
		{
			ans += bit_a.sum(now);
		}

		ans += n - i;
		cout << ans << endl;
	}
	return 0;
}
