#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	
	vector<int> v(n);
    vector<int> ans;
	for(int i=0;i<n;i++)
	{
	  cin>>v[i];
       if(v[i]==i+1)
       {
       	 ans.push_back(i+1);
       }
	}
    int at=0;
	 for(int i=0;i<n;i++)
	 {
	 	if(v[i]==i+1)
	 	{   
	 		at++;
	 		if(i+1<n&& v[i+1]==i+2)
	 		{
	 			i++;
	 		}
	 	}
	 }

	 cout<<at<<"\n";
}