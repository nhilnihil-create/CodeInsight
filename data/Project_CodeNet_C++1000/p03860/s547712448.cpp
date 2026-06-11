#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin,s); 
	string t;
	
	for(int i=0;i<s.size()-1;i++)
	{
	    if(i==0)
	    {
	        t+=toupper(s[i]);
	    }
	    else if(s[i]==' ')
	    {
	        t+=toupper(s[i+1]);
	    }
	} 
	cout<<t<<endl;
	return 0;
}