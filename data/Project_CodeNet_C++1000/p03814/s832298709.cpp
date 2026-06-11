#include<iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int count_b=0;
	int count_e=0;
	for(int i=0; i<(int)s.size(); i++){
			if(s[i] == 'A'){
				count_b = i;
				break;
			}
	}
	for(int i=(int)s.size(); i>=0; i--)
			if(s[i-1] == 'Z'){
				count_e=i;
				break;
			}
	
	count_e -= count_b;

	cout << count_e << endl;
}