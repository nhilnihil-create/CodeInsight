#include <bits/stdc++.h>
using namespace std;
#include <string.h>


int main()
{
	char str[100];
	int i,flag=1;
	map<char,int> data;
	
	scanf("%s",str);
	
	for(i=0;i<strlen(str);i++)
	{
		data[str[i]]++;
	}
	
	for(i='a';i<'z';i++)
	{
		if(data[i]>1)
		{
			flag = 0;
			break;
		}
	} 
	
	if(flag == 1) cout << "yes";
	else cout << "no";
	
}