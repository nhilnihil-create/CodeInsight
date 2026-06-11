#include <bits/stdc++.h>
using namespace std;

string S;
int suma,sumb;

int main()
{
	cin>>S;
	for(int i=0;i<S.size();i++)
	{
		if(S[i] == 'S') suma++;
		if((suma)&&(S[i]=='T'))
		{
			suma--;
			sumb+=2;
		}
	}
	cout<<S.size()-sumb<<endl;
}