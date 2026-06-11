#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int N,K,len=0;
	cin >> N >> K;
	int l[55];
	int i = 0;
	while (i < N)
		cin >> l[i++];
	sort(l, l+N, greater<int>());
	i = 0;
	while (i < K)
	{
		len += l[i];
		i++;
	}
	cout << len << endl;
	return 0;
}