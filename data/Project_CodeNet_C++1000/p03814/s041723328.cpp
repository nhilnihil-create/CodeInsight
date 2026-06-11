#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	//stack<int> q,w;
	//freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin>>s;
    ll temp,t,a;
    //a=s.length();
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='A')
    	{
    		temp=i+1;
    		break;
    	}
    }
     for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='Z')
    	{
    		a=i+1;
    		
    	}
    }
   
    cout<<a-temp+1<<endl;
}