#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    set<char>a;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    	a.insert(s[i]);
    (a.size()==s.length())?
    	cout<<"yes" : cout<<"no";
}