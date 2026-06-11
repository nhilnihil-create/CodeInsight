#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long int i,g;
    map<char,int>a;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        a[s[i]]++;
    }
    g=1;
    for(i=0;i<s.size();i++)
    {
        if(a[s[i]]%2!=0)
        {
            g=0;
            break;
        }
    }
    if(g)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
