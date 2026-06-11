#include <bits/stdc++.h>
using namespace std;



int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	
	string a,b;

	cin>>a>>b;

	if(a.size()>b.size())
	{
		cout<<"GREATER";
	}
	else if(a.size()<b.size())
		cout<<"LESS";

	else
	{
		int j =0;
		for(int i=0;i<a.size();i++)
		{

			int x = a[i]-'0';
			int y = b[i]-'0';

		//	cout<<x<<" "<<y;
			if(x>y){
				j = 1;
				break;
			}
			else if(x<y)
			{
				j = 2 ;
				break;
			}
		}

		if(j == 0)cout<<"EQUAL";
		else if(j==1)
			cout<<"GREATER";
		else
			cout<<"LESS";

	}
    return 0;
		
}






