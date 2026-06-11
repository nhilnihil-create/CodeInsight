#include <iostream>
#include<string>
using namespace std;
int main()
{  int n, x = 0, max = 0;
				cin >> n;
				string s;
				char arr[1000];
				//s.length() = n;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
				if (arr[i] == 'I')
				{
					x += 1;
					if (x > max)
						max = x;
				}
				else
				{
					x -= 1;
					if (x > max)
						max = x;
				}
			}
			cout << max;
    return 0;
}