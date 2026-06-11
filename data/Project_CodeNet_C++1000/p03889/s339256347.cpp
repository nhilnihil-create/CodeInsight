#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if(s.size()&1) 
	{
        printf("No");
        return 0;
    }
	for(int i=0; i<s.size()/2; i++) 
	{
        int r=abs(s[i]-s[s.size()-i-1]);
        if(r!=1&&r!=2) 
        { 
            cout<<"No";
            return 0;
        }
    }
	cout<<"Yes";
	return 0;
}