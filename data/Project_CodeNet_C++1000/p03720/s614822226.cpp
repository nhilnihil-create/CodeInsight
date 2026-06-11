#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
  	int n, m, tmp, next;
  	cin >> n >> m;
  	int arr[50]{};
  	for(int i = 0; i < m; i++)
    {
      cin >> tmp >> next;
      arr[tmp-1]++;
      arr[next-1]++;
    }
  	for(int i = 0; i < n; i++)
      cout << arr[i] << "\n";
  
	return 0;
}