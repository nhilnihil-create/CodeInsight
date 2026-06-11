#include<bits/stdc++.h>
using namespace std;
int main()
{  
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string a ,b;
	cin >> a >> b;
	int len1=a.size();
	int len2=b.size();
		for(int i=0;i<len1;i++)

		{
			cout<< a[i];
			if(i<len2)
			
			{
				cout<<b[i];
			}
		}
	
	
}