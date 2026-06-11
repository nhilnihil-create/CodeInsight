#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main()
{
    getline(cin,s);
    ss=s;
	reverse(ss.begin(),ss.end());
    for(int i=0;i<ss.size();i++)
        switch(ss[i])
		{
            case 'b':ss[i]='d';break;
            case 'd':ss[i]='b';break;
            case 'p':ss[i]='q';break;
            case 'q':ss[i]='p';break;
        }
    s==ss?printf("Yes\n"):printf("No\n");
    return 0;
}