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
	  



	string s; cin >> s;
	for (int i = 0; i < 19; i++){
		if (s[i] != ',')
			cout << s[i];
		else
			cout << " ";

	}
		return 0;
	
}
