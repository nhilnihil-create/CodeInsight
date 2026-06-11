#include <bits/stdc++.h>
using namespace std;
int main()

{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n ;
	cin >> n;
	int res=0;
	int max =0;
	string s;
	cin >> s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='I')

		{
			res=res+1;
		}
        if(s[i]=='D')
		{
			res=res-1;
		}
		if(max<res)

		{
			max=res;
		}


	}
	cout<< max<<"\n";
}
