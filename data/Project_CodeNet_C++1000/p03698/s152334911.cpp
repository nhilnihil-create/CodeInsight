#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
  	string s;
  	cin >> s;
  	bool check = false;
  	int arr['z'-'a'+1]{};
  	for(int i = 0; i < s.size(); i++)
    {
      arr[s[i] - 'a']++;
      if( arr[ s[i] - 'a'] > 1 )
        check = true;
    }
  	if( check == false )
      cout << "yes";
  	else
      cout << "no";
	return 0;
}