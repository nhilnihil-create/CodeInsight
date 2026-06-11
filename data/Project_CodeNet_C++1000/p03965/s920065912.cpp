#include<iostream>
#include<string>
using namespace std;
string s;
int len,x,y,ans;
int main()
{
	cin>>s;
	len = s.length();
    for(int i=0;i<len;i++)
	{
        if(x == y) {
            x++;
            if(s[i]=='p') ans--;
        }
        else {
            y++;
            if(s[i]=='g') ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}