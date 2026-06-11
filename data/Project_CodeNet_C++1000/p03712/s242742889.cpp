#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	int n, m;
	cin >> n >> m;
	char arr[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
			
	for(int i = 0; i < m+2; i++)
		cout << "#";
	cout << "\n";
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if( j == 0 )
				cout << "#";
			cout << arr[i][j];
			if( j == m-1 )
				cout << "#\n";
		}
			
	for(int i = 0; i < m+2; i++)
		cout << "#";
}