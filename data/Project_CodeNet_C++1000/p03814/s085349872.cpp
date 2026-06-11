#include<iostream>
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

int main(){

	ll();


	string s;
	cin >> s;
	int x, y;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A'){
			x = i;
			break;
		}
	}
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == 'Z'){
			y = i;
			break;
		}
	}
	cout << (y - x) + 1 << endl;
}