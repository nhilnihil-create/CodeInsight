#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
const int N=200500; 
char a[N];
int main() 
{
	stack<char> b;
	scanf("%s",&a);
	int size=strlen(a);
	char ch;
	b.push(a[0]);
	for(int i=1;i<size;i++)
	{
		if(!b.empty())
		{
			ch=b.top();
			if(ch=='S'&&a[i]=='T') 
				b.pop();
			else 
				b.push(a[i]); 
		}
		else b.push(a[i]);	
	}
	int size1=b.size();
	printf("%d\n",size1);
	return 0;
 } 