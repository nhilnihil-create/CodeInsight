#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll two[65];
vector<int> seq;
int now;

int main()
{
	int tmp = 1;
	ll N;
	scanf("%lld", &N);
	for(int i=0; i<60; i++) two[i] = 1LL<<i;
	int top = 0;
	while(two[top+1]-1 <= N) top++;
	N -= (two[top]-1);
	for(int i=1; i<=top; i++) seq.push_back(i);
	for(int i=1; i<=top; i++) seq.push_back(i);
	now = top;
	for(int i=40; i>=1; i--)
	{
		while(N >= two[i-1])
		{
			now ++;
			seq.push_back(now);
			seq.insert(seq.begin()+i-1, now);
			N -= two[i-1];
		}
	}
	printf("%d\n", seq.size());
	for(auto it=seq.begin(); it!=seq.end(); it++) printf("%d ", *it);
	putchar('\n');
	return 0;
}