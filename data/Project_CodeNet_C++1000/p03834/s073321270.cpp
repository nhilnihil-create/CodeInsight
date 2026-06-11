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

int main() {

	ll();
	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (i==5||i==13)
		{
			cout << " ";
			continue;
			
		}
		
		cout << s[i];
	}
	cout << endl;

}