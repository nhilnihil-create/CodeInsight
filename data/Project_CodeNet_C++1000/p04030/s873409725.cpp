#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,s1;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='B')
        s1+=s[i];
        else
        {
            if(s1.length()>=1)
            s1.pop_back();
        }
    }
    cout<<s1<<endl;
	return 0; 
} 
