#include <bits/stdc++.h>
using namespace std;




int main() {
	int N,divNum=0,ans=1;
	cin >> N;
	for (int i = 1; i <= N ; i++)
	{
		if (i % 2 != 0)continue;
		int tmp = i;
		int count = 0;
		while (true)
		{
			if (tmp%2!=0)
			{
				break;
			}
			tmp /= 2;
			count++;
		}
		if (count>divNum)
		{
			divNum = count;
			ans = i;
		}
	}
	cout << ans << endl;
}
