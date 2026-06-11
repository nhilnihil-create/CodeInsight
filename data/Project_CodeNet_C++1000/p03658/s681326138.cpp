#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K, l;
	vector<int> v;

	cin >> N >> K;

	for(int i = 1; i <= N; i++)
    {
        cin >> l;
        v.push_back(l);
    }

    sort(v.begin(), v.end(), greater<int>());

    int maxLength = 0;
    int len = v.size();
    for(int i = 0; i < K; i++)
        maxLength = maxLength + v[i];

    cout << maxLength << endl;

	return 0;
}
