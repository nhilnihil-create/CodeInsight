#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[16],s0[16]={'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};
	gets(s);
	int x=0;
	for(int i=0;i<16;i++)
	if(s[i]!=s0[i]) x++;
	cout<<x;
}