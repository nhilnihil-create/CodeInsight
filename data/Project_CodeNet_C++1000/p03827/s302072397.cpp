#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();

	int n,x=0,t=0;
	char s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s =='I')
		{
			x++; 
			if (x>t)
				t = x;
		}
		if (s == 'D')
		{
			x -= 1;
		}

	}
	if (t > x)
		cout << t << endl;
	else
		cout << x << endl;
}