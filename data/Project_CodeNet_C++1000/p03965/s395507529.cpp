#include<bits/stdc++.h>
using namespace std;

int main()
{
  	string s;
  	cin>>s;
  	int n = s.size(), p = 0;
  	for(int i = 0; i < s.size(); i++)
    {
    	if(s[i] == 'p')
          	p++;
    }
  	cout<<(n/2)-p<<"\n";
	return 0;
}