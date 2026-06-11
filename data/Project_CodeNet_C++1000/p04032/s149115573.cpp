#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	
	int n = str.length();
	
	for(int i = 0; i < n; i++)
	{
		if((i - 1) >= 0 && str[i] == str[i - 1]){
			cout << (i) << " " << (i + 1);
			return 0;
		}
		
		if((i - 2) >= 0 && str[i] == str[i - 2]){
			cout << (i - 1) << " " << (i + 1);
			return 0;
		}
	}
	
	cout << "-1 -1";
	return 0;
}