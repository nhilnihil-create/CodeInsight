#include <iostream>
#include <string>
using namespace std ; 
int main() {
	string s;
	
	getline(cin,s);
	
	int n = s.size();
	
	for (int i = 0; i < n; i++)
	{
		if(i == 5  || i == 13)
		{
			s.replace(5,1," ");
			s.replace(13,1," ");
		}
	}
	
	cout << s << endl;
	
}