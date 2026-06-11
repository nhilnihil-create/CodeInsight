#include <stdlib.h> 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

int main()
{
	int n,a,b;
	string s;
	
	cin>>n>>a>>b;
	cin>>s;
	
	int ab = a + b;
	int i = 0;
	
	while( i < s.size())
	{
		if( s[i] == 'a')
		{
			if( ab != 0) 
			{
				cout<<"Yes"<<endl;
				ab--;
			}
			else cout<<"No"<<endl;
		}
		
		else if( s[i] == 'b')
		{
			if(ab != 0 && b != 0) 
			{
				cout<<"Yes"<<endl;
				ab--;
				b--;
			}
			else cout<<"No"<<endl;
		}
		
		else if( s[i] == 'c') cout<<"No"<<endl;
		
		i++;
	}
	return 0;
}
