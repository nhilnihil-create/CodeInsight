#include <bits/stdc++.h>
using namespace std;
int main()
 
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int w,a,b,preo,finalo;
	cin >> w >> a >> b ;
	
	if(b>a)
	{
		if(a+w>b)
		{
			cout<< 0;
		}
		else{
			preo=abs(b-a);
			finalo=abs(preo-w);
			cout << finalo;
		}
		
	}
	else if(a>b)
		{
			if(b+w>a)
		{
			cout<< 0;
		}
		else
		{
			preo=abs(b-a);
			finalo=abs(preo-w);
			cout << finalo;
		}
	    	
	    }
	else if(a==b)
	    {
	    	cout <<0;
	    }
}