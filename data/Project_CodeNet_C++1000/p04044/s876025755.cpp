#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,l;
	string s;
	cin>>n>>l;
	vector <string> str;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		str.push_back(s);
		
	}
	stable_sort(str.begin(),str.end());
	for(int i=0;i<n;i++)
	{
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}