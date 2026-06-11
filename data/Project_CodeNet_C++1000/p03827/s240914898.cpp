#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
	  



	int n,x = 0,k=-2000; char c[105]; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> c[i];
		if (c[i] == 'I') x++;
		if (c[i] == 'D')x--;
		if (x > k)
			k = x;
	} 
	if (k> 0)
		cout << k << endl;
	else 
		cout << 0 << endl;
		return 0;
	
}
