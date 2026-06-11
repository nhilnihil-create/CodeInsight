#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N,ans=0;
	cin >> N;
	vector<int> A(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> A.at(i);
	}
	if (A.at(0)==1)
	{
		A.at(0) = A.at(0);
		A.at(1) = 1;
		
		ans++;
	}
	for (size_t i = 1; i < N-1; i++)
	{
		if (A.at(i)==i+1)
		{
			A.at(i + 1) = i+1;
			ans++;
		}
	}
	if (A.at(N-1)==N)
	{
		ans++;
	}
	cout << ans;
}