#include <bits/stdc++.h>
 
using namespace std;

int A[100001];
int n;
long long int res[100001];

struct data
{
	int val;
	int idx;
};

bool operator<(data a,data b)
{
	if(a.val==b.val)
	{
		return a.idx > b.idx;
	}
	return a.val < b.val;
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> A[i];
	}

	priority_queue <data> pque;
	for(int i=1;i<=n;i++)
	{
		data d;
		d.val = A[i];
		d.idx = i;
		pque.push(d);
	}

	int cnt = 0;
	int iidx = 1e9;
	while(1)
	{
		int idx = pque.top().idx;
		long long int val = pque.top().val;
		long long int val2 = 0;
		if(idx==1)
		{
			break;
		}

		while(!pque.empty())
		{
			if(pque.top().val < val)
			{
				val2 = pque.top().val;
				break;
			}
			iidx = min(iidx,pque.top().idx);
			cnt++;
			pque.pop();
		}

		res[iidx] += cnt*(val-val2);
	}

	for(int i=1;i<=n;i++)
	{
		if(A[i] < A[1])
		{
			res[1] += A[i];
		}
		else
		{
			res[1] += A[1];
		}
	}

	for(int i=1;i<=n;i++)
	{
		cout << res[i] << '\n';
	}
	
	return 0;
}