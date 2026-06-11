#include<bits/stdc++.h>
using namespace std;
int main()
{   
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	for(int i  = 0;i<19;i++)
	{

		if(i==5||i==13)
		{
			cout <<" ";
		}
		else
		{
			cout << s[i];
		}
	}
}