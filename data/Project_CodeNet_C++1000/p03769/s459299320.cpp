#include <iostream>

using namespace std;
int s[200],pre[100],back[100];
int main()
{
	long long n;
	cin >> n;
	int tmp = 100,r = 1,l = 1;
	while(n)
	{
		if(n & 1)
		{
			n >>= 1;
			back[r ++] = tmp --;
		}
		else
		{
			n --;
			pre[l ++] = tmp --;
		}
	}
	cout << 2 * (100 - tmp) << endl;
	for(int i = 1;i < l;i ++)
		printf("%d ",pre[i]);
	for(int i = r - 1;i > 0;i --)
		printf("%d ",back[i]);
	for(int i = tmp + 1;i < 100;i ++)
		printf("%d ",i);
	cout << 100 << endl;
	return 0;
}