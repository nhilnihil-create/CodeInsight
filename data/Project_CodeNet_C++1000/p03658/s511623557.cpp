#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, k, c = 0; cin >> n >> k;
	int A[n];
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	sort(A, A+n);
	for (int i = n-k; i < n; ++i)
		c += A[i];
	cout << c << endl;
}

