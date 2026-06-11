#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;
int main()
{
	string s;
	cin >> s;
	int arr['z'-'a'+1]{};
	for(int i = 0; i < s.size(); i++)
		arr[ s[i] - 'a' ]++;
	for(int i = 0; i <= 'z' - 'a'; i++)
		if( arr[i] == 0 )
		{
			cout << (char)(i+'a');
			return 0;
		}
	cout << "None";
	return 0;
}