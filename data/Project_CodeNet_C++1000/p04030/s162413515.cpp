#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	string s;
	cin>>s;
	vector <int> ve;
	for(int i=0;i<s.size();i++)
	{
		if (s[i]=='0')
		{
			ve.push_back(0);
		}
		else if (s[i]=='1')
		{
			ve.push_back(1);
		}
		else {
		if(ve.size()!=0)
		{
            ve.pop_back();             
		}
	}

	}
			for(int j=0;j<ve.size();j++)
			{
			   cout<<ve[j];
			}

	return 0;
}