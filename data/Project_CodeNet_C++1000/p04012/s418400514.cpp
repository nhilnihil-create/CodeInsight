#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;


int main()
{
   
   string w;
   cin>>w;
   size_t i;
	
   map<char,int>  count;
   
   for(char c:w)
   {
   	
   	count[c]++;
   	
   }
   
   
   	
    for(i=0;i<w.size();i++)
	{

	     if(count[w[i]]%2!=0)
		 {
		 	
		 	break;
		 	
		 }	
		
		
	}	
	
	
	
	if(i==w.size())
	{
		
		cout<<"Yes"<<endl;
		
	}
	
	
	else
	{
		
		
		cout<<"No"<<endl;
	}
	
	
	
	
	return 0;
	
}