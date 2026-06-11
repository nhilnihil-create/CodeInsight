#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<char,int>mp;
    
    string n;
    cin>>n;
    
    for(int i=0;i<n.size();i++)
    	mp[n[i]]++;
    
    bool flag =false;
    
    for(auto x:mp)
    {
    	if(x.second%2==0)
    		flag=true;
    	else if(x.second%2!=0)
    	{	flag=false;
    		break;}
    }
    if(flag==true)
    	cout<<"Yes";
    else
    	cout<<"No";
    
    
    
    
	return 0;
}