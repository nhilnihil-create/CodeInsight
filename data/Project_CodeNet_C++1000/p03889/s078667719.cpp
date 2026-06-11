#include<bits/stdc++.h>
using namespace std;
stack<char>m;
string a;
int main()
{
    cin>>a;
    int n=a.size();
    for (int i=0;i<n;i++)
      m.push(a[i]);
    bool j=1;
    for(int i=0;i<n;i++)
	{
        char top=m.top();
        if (top=='b')
		  top='d';
        else if (top=='d')
		  top='b';
        else if (top=='p')
		  top='q';
        else if (top=='q')
		  top='p';
        if (top==a[i])
		{
            j=1;
            m.pop();
        }
        else
		{
            j=0;
            break;
        }
    }
    if(j==0)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
    return 0;
}