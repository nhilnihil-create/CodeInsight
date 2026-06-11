#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	int w, a, b; cin >> w >> a >> b;
	if (a>b)
		swap(a, b);
	if (b - (a + w)>0)
		cout << b - (a + w);
	else
		cout << "0\n";
	
}