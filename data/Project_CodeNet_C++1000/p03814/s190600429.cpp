#include <bits/stdc++.h>
using namespace std;
int main()

{

	string s;
	int start_index,last_index;
	cin>>s;
	for(int i=0;i<s.size();i++)

	{
		if(s[i]=='A')
		{
			start_index=i;
			break;
		}
	}

		for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='Z')
		{
          last_index=i;
          break;
		}
	}
	cout << last_index-start_index+1<<"\n";



}
