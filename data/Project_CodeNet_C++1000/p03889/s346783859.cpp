#include <iostream>
using namespace std;
string st;
int l;
int main()
{
	cin>>st;
	l=st.size();
	for (int i=0;i<l;i++)
	{
	    if (st[i]=='p') 
	    {
	    	if (st[l-i-1]!='q') 
	    	{
	    		cout<<"No"<<endl;
	    		return 0;
	    	}
	    }
	       if (st[i]=='q') 
	    {
	    	if (st[l-i-1]!='p') 
	    	{
	    		cout<<"No"<<endl;
	    		return 0;
	    	}
	    }
	       if (st[i]=='b') 
	    {
	    	if (st[l-i-1]!='d') 
	    	{
	    		cout<<"No"<<endl;
	    		return 0;
	    	}
	    }
	       if (st[i]=='d') 
	    {
	    	if (st[l-i-1]!='b') 
	    	{
	    		cout<<"No"<<endl;
	    		return 0;
	    	}
	    }
	}
	cout<<"Yes"<<endl;
}