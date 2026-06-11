#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int k=1;int x=0;
    char c=getchar();
    while ((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')
    k=-1,c=getchar();
    while(c>='0'&&c<='9')
    x=x*10+c-'0',c=getchar();
    return k*x;
}
string a;
int main()
{
    cin>>a;
    string b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d')
			a[i]='b';
        else if(a[i]=='p')
			a[i]='q';
        else if(a[i]=='q')
			a[i]='p';
    }
    if(a==b)
		cout<<"Yes";
    else
		cout<<"No";
}
