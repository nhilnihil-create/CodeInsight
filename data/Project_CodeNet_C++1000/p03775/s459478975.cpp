#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int64_t N,tmp,ans=10e11;
	cin >> N;
	for (int64_t i = 1; i*i <= N ; i++)
	{
		if (N%i==0)
		{
			tmp = max(i, N / i);
			ans = min(ans, tmp);
		}
	}
	
	string a = to_string(ans);
	
	cout << a.size() << endl;
}