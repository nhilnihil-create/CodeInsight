#include <bits/stdc++.h>
using namespace std;

int flag=0;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
	{
        if (s[i]==s[i+1])
		{
            cout<<i+1<<" "<<i+2<<endl;
            flag=1;
            return 0;
        }
        else if (i<s.size()-2&&s[i]==s[i+2])
		{
            cout<<i+1<<" "<<i+3<<endl;
            flag=1;
            return 0;
        }
    }
    if (!flag)  cout<<-1<<" "<<-1<<endl;
    return 0;
}