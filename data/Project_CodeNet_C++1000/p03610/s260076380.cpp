
#include<bits/stdc++.h>
using namespace std;
int main()
    {
    	cin.tie(0);
        ios::sync_with_stdio(0);
        string s,S;cin>>s;
    	for (int i = 0; s[i] ; ++i)
    	{
    		if(i%2==0){
    			S+=s[i];
    		}
    	}
        cout<<S;
    	return 0;
    }

