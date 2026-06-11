#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)n; ++i)

vector<int> odd, even, out;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	f(i, 0, m){
		int t;
		scanf("%d", &t);
		if (t & 1)odd.push_back(t);
		else even.push_back(t);
	}
	if (odd.size() > 2)printf("Impossible\n"), exit(0);
	if (n == 1)printf("1\n1\n1\n"), exit(0);
	if (even.empty() && odd.size() == 1)printf("%d\n2\n1 %d\n", odd[0], odd[0] - 1), exit(0);
	if (!odd.empty())out.push_back(odd[0] + 1);
	else out.push_back(1);
	f(i, 0, even.size())out.push_back(even[i]);
	if (odd.size() == 2)out.push_back(odd[1] - 1);
	else --out.back();
	if (!out.back())out.pop_back();
	printf("%d", odd.empty() ? even[0] : odd[0]);
	f(i, odd.empty(), even.size())printf(" %d", even[i]);
	if (odd.size() == 2)printf(" %d", odd[1]);
	printf("\n%d\n%d", (int)out.size(), out[0]);
	f(i, 1, out.size())printf(" %d", out[i]);
	printf("\n");
}
