#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='N')
        a++;
        if(s[i]=='S')
        b++;
        if(s[i]=='E')
        c++;
        if(s[i]=='W')
        d++;
    }
    if((a>0&&b>0&&c==0&&d==0)||(c>0&&d>0&&a==0&&b==0))
        {cout<<"Yes"<<endl;return 0;}
    if(a>0&&b>0&&c>0&&d>0)
        {cout<<"Yes"<<endl;return 0;}
    cout<<"No"<<endl;
    return 0;
}