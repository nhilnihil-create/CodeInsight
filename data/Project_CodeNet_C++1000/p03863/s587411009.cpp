#include<iostream>
#include<string>
using namespace std;
string s;
int a;
int main()
{
    cin>>s;
    a=s.length();
    if(s[0]==s[a-1])
	{
        if(a%2==0)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
            return 0;
    }
    else
	{
        if(a%2==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
            return 0;
    }
}